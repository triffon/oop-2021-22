# Creating Thumbnails

## Problem

```c++
void create_thumbnail(const char * original_name, const char * thumbnail_name,
                      uint32_t x, uint32_t y, uint32_t width, uint32_t height)
```

Create a new .bmp file (same format as grayscale problem) with the given thumbnail_name by copying a rectangle from the other .bmp file (original_name) with lower left corner at coordinates (x; y) and the given dimensions (each side is parallel to one of the axes)

## Notes

- Carefully copy the metadata and alter what you need
- Note the order of the lines
- You don't have to check for I/O or format errors, assume everything goes right

## Example

```c++
create_thumbnail("monkas.bmp", "140-300-200-180-example.bmp", 140, 300, 200, 180);
```

![monkas](monkas.bmp?raw=true "monkas.bmp")

![140-300-200-180-example](140-300-200-180-example.bmp?raw=true "140-300-200-180-example.bmp")