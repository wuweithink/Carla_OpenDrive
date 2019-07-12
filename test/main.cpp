#include <iostream>

#include "OpenDrive.h"
#include <carla/geom/Location.h>
#include <carla/geom/Math.h>
#include <carla/opendrive/OpenDriveParser.h>
#include <carla/road/MapBuilder.h>
#include <carla/road/element/RoadInfoElevation.h>
#include <carla/road/element/RoadInfoGeometry.h>
#include <carla/road/element/RoadInfoMarkRecord.h>
#include <carla/road/element/RoadInfoVisitor.h>
#include <pugixml/pugixml.hpp>
#include <fstream>
#include <string>

using namespace carla::road;
using namespace carla::road::element;
using namespace carla::geom;
using namespace carla::opendrive;

const std::string BASE_PATH = LIBOPENDRIVE_TEST_CONTENT_FOLDER "/OpenDrive/";

int main(int argc, char *argv[])
{
    for (const auto& file : util::OpenDrive::GetAvailableFiles()) {
        std::cout << "name: " << file << std::endl;
        auto map = OpenDriveParser::Load(util::OpenDrive::Load(file));
        auto waypoints = map->GenerateWaypoints(1.0);
        std::cout << waypoints.size() << std::endl;
        for (auto& wp : waypoints)
        {
            std::cout << "lane width: " << map->GetLaneWidth(wp) << std::endl;

        }
    }
    return 0;
}
