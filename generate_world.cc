#include <iostream>
#include <sstream>
#include <fstream>  

int main(){	
	std::ofstream outfile2 ("fake_world.world");
	char buf[4096];
    sprintf(buf,"\
    <?xml version=\"1.0\"?>\n\
	<sdf version=\"1.4\">\n\
	  <world name=\"animated_box_world\">\n\
	    <!-- Ground Plane -->\n\
	    <include>\n\
	      <uri>model://ground_plane</uri>\n\
	    </include>\n\
	    <include>\n\
	      <uri>model://sun</uri>\n\
	    </include>\n\
	    \
	    <model name=\"box\">\n\
	      <pose>0 0 0.5 0 0 0</pose>\n\
	      <link name=\"link\">\n\
	        <collision name=\"collision\">\n\
	          <geometry>\n\
	            <box>\n\
	              <size>4.172357674029369079 1.738894971252158861 1.369794373548019362</size>\n\
	            </box>\n\
	          </geometry>\n\
	        </collision>\n\
	        <visual name=\"visual\">\n\
	          <geometry>\n\
	            <box>\n\
	              <size>4.172357674029369079 1.738894971252158861 1.369794373548019362</size>\n\
	            </box>\n\
	          </geometry>\n\
	        </visual>\n\
	      </link>\n\
	      <plugin name=\"push_animate\" filename=\"libanimated_box.so\"/>\n\
	    </model>\n\
	    \
	    <model name=\"box2\">\n\
	      <pose>0 -10 0.5 0 0 0</pose>\n\
	      <link name=\"link\">\n\
	        <collision name=\"collision\">\n\
	          <geometry>\n\
	            <box>\n\
	              <size>8.172357674029369079 2.738894971252158861 2.369794373548019362</size>\n\
	            </box>\n\
	          </geometry>\n\
	        </collision>\n\
	        <visual name=\"visual\">\n\
	          <geometry>\n\
	            <box>\n\
	              <size>8.172357674029369079 2.738894971252158861 2.369794373548019362</size>\n\
	            </box>\n\
	          </geometry>\n\
	        </visual>\n\
	      </link>\n\
	      <plugin name=\"push_animate\" filename=\"libanimated_box.so\"/>\n\
	    </model>\n\
	  </world>\n\
	</sdf>\n"
	);

	outfile2 << buf;
	outfile2.close();

	return 0;
}