# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "raytracer.h"
# include "my.h"

void			my_puterr(char const *filename)
{
  if (errno == EACCES)
    {
      write(2, "Permssion denied\n", 17);
    }
  else if (errno == ENOENT)
    {
      write(2, "cat: ", 5);
      write(2, filename, my_strlen(filename));
      write(2, " : No such file or directory\n", 29);
    }
  else if (errno == EISDIR)
    {
      write(2, filename, my_strlen(filename));
      write(2, " is a directory\n", 16);
    }
}

bitmap_file_header_t	file_header(int const file_size)
{
  bitmap_file_header_t	file_h;

  file_h.bf_type = BM_MAGIC;
  file_h.bf_size = sizeof(bitmap_file_header_t) +
    sizeof(bitmap_file_info_t) + file_size;
  file_h.bf_reserved1 = 0;
  file_h.bf_reserved2 = 0;
  file_h.bf_off_bits = sizeof(bitmap_file_header_t) +
    sizeof(bitmap_file_info_t);
  return (file_h);
}

bitmap_file_info_t	file_info(int dpi)
{
  bitmap_file_info_t	file_i;

  file_i.size = sizeof(bitmap_file_info_t);
  file_i.width = WIDTH;
  file_i.height = HEIGHT;
  file_i.planes = 1;
  file_i.bits = 24;
  file_i.compression = 0;
  file_i.image_size = WIDTH * HEIGHT * 4;
  file_i.x_resolution = (int)(INCHES_PER_UNIT) * dpi;
  file_i.y_resolution = (int)(INCHES_PER_UNIT) * dpi;
  file_i.n_colors = 0;
  file_i.important_colors = 0;
  return (file_i);
}

int			draw_bmp(char const *file_name)
{
  int			i;
  int			j;
  int			fd;
  bitmap_file_header_t	file_h;
  bitmap_file_info_t	file_i;
  color_t		color;

  i = 0;
  file_h = file_header(WIDTH * HEIGHT);
  file_i = file_info(72);
  if ((fd = open(file_name, O_CREAT | O_WRONLY)) < 0)
    {
      my_puterr(file_name);
      return (1);
    }
  write(fd, &file_h, sizeof(bitmap_file_header_t));
  write(fd, &file_i, sizeof(bitmap_file_info_t));
  while (i < HEIGHT)
    {
      j = 0;
      while (j < WIDTH)
	{
	  color.r = 255;
	  color.g = 100;
	  color.b = 100;
	  write(fd, &color, sizeof(color_t));
	  j += 1;
	}
      i += 1;
    }
  close(fd);
  return (0);
}

int			main(int ac, char **av)
{
  if (ac != 2)
    {
      my_putstr("usage: ./raytracer.exe output_file\n");
      return (EXIT_SUCCESS);
    }
  my_putstr("Raytracer start...\n");
  if (draw_bmp(av[1]))
    {
      return (EXIT_FAILURE);
    }
  my_putstr("RayTracer end !\n");
  return (EXIT_SUCCESS);
}
