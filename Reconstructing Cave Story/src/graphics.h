#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>
#include <map>

struct SDL_Surface;
struct SDL_Rect;

struct Graphics {
   typedef SDL_Surface* SurfaceID;
   Graphics();
   ~Graphics();

   SurfaceID loadImage(const std::string& file_path);

   void blitSurface(SurfaceID source,
      SDL_Rect* source_rectangle,
      SDL_Rect* destination_rectangle);
   void flip();
   void clear();
private:
   typedef std::map<std::string, SDL_Surface*> SpriteMap;
   SpriteMap sprite_sheets_;
   SDL_Surface* screen_;
};

#endif
