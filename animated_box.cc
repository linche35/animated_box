/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>

namespace gazebo
{
  class AnimatedBox : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
     // std::cout << "name = " << _sdf->GetName() << std::endl;
     //std::cout << ""
     std::cout << "_parent->GetSDF()->GetAttribute(\"name\")->GetAsString() = " << _parent->GetSDF()->GetAttribute("name")->GetAsString() << std::endl;
     std::string model_name = _parent->GetSDF()->GetAttribute("name")->GetAsString();

      // Store the pointer to the model
      this->model = _parent;

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 10 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("test", 10.0, true));

        gazebo::common::PoseKeyFrame *key;

        if ( model_name == "box"){
          // set starting location of the box
          key = anim->CreateKeyFrame(0);
          key->Translation(ignition::math::Vector3d(-20, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));

          // set waypoint location after 2 seconds
          key = anim->CreateKeyFrame(2.0);
          key->Translation(ignition::math::Vector3d(-10, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(4.0);
          key->Translation(ignition::math::Vector3d(0, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(6.0);
          key->Translation(ignition::math::Vector3d(10, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(8.0);
          key->Translation(ignition::math::Vector3d(20, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));

          // set final location equal to starting location
          key = anim->CreateKeyFrame(10);
          key->Translation(ignition::math::Vector3d(30, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));
        }

        else{
          // set starting location of the box
          key = anim->CreateKeyFrame(0);
          key->Translation(ignition::math::Vector3d(-20, -10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));

          // set waypoint location after 2 seconds
          key = anim->CreateKeyFrame(2.0);
          key->Translation(ignition::math::Vector3d(-10, -6, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(4.0);
          key->Translation(ignition::math::Vector3d(0, -2, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(6.0);
          key->Translation(ignition::math::Vector3d(10, 2, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));


          key = anim->CreateKeyFrame(8.0);
          key->Translation(ignition::math::Vector3d(20, 6, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));

          // set final location equal to starting location
          key = anim->CreateKeyFrame(10);
          key->Translation(ignition::math::Vector3d(30, 10, 0));
          key->Rotation(ignition::math::Quaterniond(0, 0, 0));
        }

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(AnimatedBox)
}
