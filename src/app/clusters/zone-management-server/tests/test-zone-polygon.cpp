/*
 *
 *    Copyright (c) 2025 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file implements a unit test suite for testing different zone
 *      polygons for self-intersection.
 *
 */

#include <vector>

#include <app/clusters/zone-management-server/zone-util.h>
#include <app/clusters/zone-management-server/zone-management-server.h>

#include <pw_unit_test/framework.h>

#include <lib/support/CodeUtils.h>

using namespace chip;
using namespace chip::Test;
using namespace chip::app;
using namespace chip::app::Clusters;
using namespace chip::app::Clusters::ZoneManagement;

// =================================
//      Unit tests
// =================================

namespace chip {
namespace app {

class TestZonePolygon : public ::testing::Test
{
public:
    static void SetUpTestSuite() { }
    static void TearDownTestSuite() { }
};

TEST_F(TestZonePolygon, TestValidZones)
{
    std::vector<TwoDCartesianVertexStruct> zone1 = {{10, 10}, {20, 10}, {20, 20}, {10, 20}};

    bool res= ZoneUtil::IsZoneSelfIntersecting(zone1);
    EXPECT_FALSE(res);
}

TEST_F(TestCHIPMem, TestSelfIntersectingZones)
{
    std::vector<TwoDCartesianVertexStruct> zone1 = {{10, 10}, {20, 20}, {20, 10}, {10, 20}};

    bool res= ZoneUtil::IsZoneSelfIntersecting(zone1);
    EXPECT_TRUE(res);
}

} // namespace app
} // namespace chip