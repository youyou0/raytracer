# pragma once

# define BM_MAGIC		0x4D42
# define WIDTH			640
# define HEIGHT			480
# define INCHES_PER_UNIT	39.375

#pragma pack(1)
typedef struct			color
{
  unsigned char			r;
  unsigned char			g;
  unsigned char			b;
}__attribute__((packed))	color_t;

/*
** Name: bitmap_file_header
** Structure variables:
**	Specifies the file type
**	Specifies the size in bytes of the bitmap file
**	Reserved1; must be 0
**	Reserved2; must be 0
**	Specifies the offset in bytes from the bitmapfileheader to the bitmap bits
*/
#pragma pack(2)
typedef struct			bitmap_file_header
{
  unsigned short		bf_type;
  unsigned int			bf_size;
  unsigned short		bf_reserved1;
  unsigned short		bf_reserved2;
  unsigned int			bf_off_bits;
} __attribute__((packed))	bitmap_file_header_t;

/*
** Name: bitmap_file_info
** Structure variables:
**	Header size in bytes
**	Width and height of image
**	Number of colour planes
**	Bits per pixel
**	Compression type
**	Image size in bytes
**	Pixels per meter
**	Number of colours
**	Important colours
*/
#pragma pack(2)
typedef struct			bitmap_file_info
{
  unsigned int			size;
  int				width;
  int				height;
  unsigned short		planes;
  unsigned short		bits;
  unsigned int			compression;
  unsigned int			image_size;
  int				x_resolution;
  int				y_resolution;
  unsigned int			n_colors;
  unsigned int			important_colors;
} __attribute__((packed))	bitmap_file_info_t;

#pragma pack(2)
typedef struct			ray
{
  int				origin;
  int				direction;
  int				distance;
} __attribute__((packed))	ray_t;

int				draw_bmp(char const *file_name);
