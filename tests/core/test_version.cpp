/**
 * @file test_version.cpp
 * @brief Tests for version functionality
 */

#include <gtest/gtest.h>
#include "mathforge/core/version.hpp"

using namespace mathforge::core;

TEST(VersionTest, VersionString) {
    std::string version = Version::getVersionString();
    EXPECT_FALSE(version.empty());
    EXPECT_NE(version.find("1.0.0"), std::string::npos);
}

TEST(VersionTest, BuildInfo) {
    std::string buildInfo = Version::getBuildInfo();
    EXPECT_FALSE(buildInfo.empty());
    EXPECT_NE(buildInfo.find("MathForge"), std::string::npos);
}

TEST(VersionTest, Copyright) {
    std::string copyright = Version::getCopyright();
    EXPECT_FALSE(copyright.empty());
    EXPECT_NE(copyright.find("2025"), std::string::npos);
}
