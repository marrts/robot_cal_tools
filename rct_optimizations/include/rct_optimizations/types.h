#ifndef RCT_TYPES_H
#define RCT_TYPES_H

#include <array>
#include <map>
#include <Eigen/Dense>

namespace rct_optimizations
{

struct CameraIntrinsics
{
  std::array<double, 4> values;

  double& fx() { return values[0]; }
  double& fy() { return values[1]; }
  double& cx() { return values[2]; }
  double& cy() { return values[3]; }

  const double& fx() const { return values[0]; }
  const double& fy() const { return values[1]; }
  const double& cx() const { return values[2]; }
  const double& cy() const { return values[3]; }
};

struct Pose6d
{
  Pose6d() = default;
  Pose6d(std::array<double, 6> l) : values(l) {}

  std::array<double, 6> values;

  double& rx() { return values[0]; }
  double& ry() { return values[1]; }
  double& rz() { return values[2]; }
  double& x() { return values[3]; }
  double& y() { return values[4]; }
  double& z() { return values[5]; }
  const double& rx() const { return values[0]; }
  const double& ry() const { return values[1]; }
  const double& rz() const { return values[2]; }
  const double& x() const { return values[3]; }
  const double& y() const { return values[4]; }
  const double& z() const { return values[5]; }
};

struct Vec3d
{
    Vec3d() = default;
    Vec3d(std::array<double, 3> l) : values(l) {}

    std::array<double, 3> values;

    double& x() { return values[0]; }
    double& y() { return values[1]; }
    double& z() { return values[2]; }
    const double& x() const { return values[0]; }
    const double& y() const { return values[1]; }
    const double& z() const { return values[2]; }
};

// Useful typedefs shared by calibrations
struct Correspondence2D3D
{
  Eigen::Vector3d in_target;
  Eigen::Vector2d in_image;
};

using CorrespondenceSet = std::vector<Correspondence2D3D>;

struct Correspondence3D3D
{
  Eigen::Vector3d in_target;
  Eigen::Vector3d in_image;
};

struct CorrespondenceMarker3D3D
{
  int id;
  int index_corner;
  Eigen::Vector3d in_target;
  Eigen::Vector3d in_image;
};

struct CorrespondenceARMulti3D3D
{
  int id;
  int index_corner;
  Eigen::Affine3d pose_axis_x_first, pose_axis_y_first, pose_axis_x_second, pose_axis_y_second;
  Eigen::Vector3d point_first, point_second;
};



using Correspondence3DSet = std::vector<Correspondence3D3D>;
using CorrespondenceMarker3DSet = std::vector<CorrespondenceMarker3D3D>;
using CorrespondenceARMulti3D3Dset = std::vector<CorrespondenceARMulti3D3D>;

// Key is marker ID and corner index. Vector is correction to object point in X, Y, and Z.
using ObjectPointCorrection3DSet = std::map<std::tuple<int, int>, Eigen::Vector3d>;
}

#endif
