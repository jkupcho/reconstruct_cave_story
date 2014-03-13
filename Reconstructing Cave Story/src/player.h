#ifndef PLAYER_H_
#define PLAYER_H_

#include "sprite.h"
#include <boost/shared_ptr.hpp>
#include <map>

struct Graphics;

struct Player {
   Player(Graphics& graphics, int x, int y);

   void update(int elapsed_time_ms);
   void draw(Graphics& graphics);

   void startMovingLeft();
   void startMovingRight();
   void stopMoving();

   private:
      enum MotionType {
         STANDING, WALKING
      };
      enum HorizontalFacing {
         LEFT, RIGHT
      };

      struct SpriteState {
         SpriteState(MotionType motion_type = STANDING,
                     HorizontalFacing horizontal_facing = LEFT) :
            horizontal_facing(horizontal_facing),
            motion_type(motion_type) {}

         MotionType motion_type;
         HorizontalFacing horizontal_facing;
      };

      friend bool operator < (const SpriteState& a, const SpriteState& b);
      void initializeSprites(Graphics& graphics);
      SpriteState getSpriteState();

      int x_, y_;
      float acceleration_x_, velocity_x_;
      HorizontalFacing horizontal_facing_;
      std::map<SpriteState, boost::shared_ptr<Sprite>> sprites_;
};

#endif //PLAYER_H_

