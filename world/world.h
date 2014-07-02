// Dan Goldberg
// Cloud object
/**
  
*/

#ifndef WORLD_H_
#define WORLD_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

#include <Eigen/Dense>

//#include <pcl/io/point_cloud.h>
//#include <pcl/io/vtk_io.h> 
//#include <pcl/io/vtk_lib_io.h> 
//#include <pcl/io/ply.h> 
#include <pcl/io/ply_io.h> 
#include <pcl/point_cloud.h>
#include <pcl/PolygonMesh.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/Vertices.h>

#include <boost/ptr_container/ptr_vector.hpp>

#include "../aux/patch.h"
#include "../aux/camera.h"
#include "../aux/triangle.h"

class World{
public:
  World();
  World(const int& nCams);
//  Cloud(CloudInfo info, std::string name);
  World(const World& c);
  virtual ~World();

  pcl::PointCloud<pcl::PointXYZ>::Ptr getPoints()const{return points_;};
  pcl::KdTreeFLANN<pcl::PointXYZ> getTree()const{return kdtree_;};
  pcl::PolygonMesh getMesh()const{return mesh_;};
  std::vector<Patch> getPatches()const{return patches_;};
  //std::vector<Eigen::MatrixXd> getCameras()const{return cameras_;};
  std::vector<Camera> getCameras()const{return cameras_;};
  std::vector<Triangle<Patch> > getTriangles()const{return triangles_;};
  size_t getN()const{return N_;};

  void setNCameras(const int& n){cameras_=std::vector<Camera>(n);};

  bool readPly(const std::string& fname);
  bool readPatchInfo(const std::string& fname);
  bool readCameras(const std::string& fname);

  std::string toString()const;
  
  friend bool operator==(const pcl::PointXYZ& p1, const pcl::PointXYZ& p2);
  friend bool operator!=(const pcl::PointXYZ& p1, const pcl::PointXYZ& p2);
  
private:
  size_t N_;
  pcl::PointCloud<pcl::PointXYZ>::Ptr points_;
  pcl::KdTreeFLANN<pcl::PointXYZ> kdtree_;
  //pcl::KdTree<pcl::PointXYZ> kdtree_;
  pcl::PolygonMesh mesh_;
  std::vector<Patch> patches_;
  std::vector<Triangle<Patch> > triangles_;
  std::vector<Camera> cameras_;

};

#endif
