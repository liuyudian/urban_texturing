// Dan Goldberg
// Camera Class

#ifndef CAMERA_H_
#define CAMERA_H_

#include <vector>

#include <Eigen/Dense>

class Camera{
public:
  Camera();
  virtual ~Camera();
  
  void setMat(Eigen::MatrixXf m){mat_=m;};
  Eigen::MatrixXf getMat()const{return mat_;};
  
  Eigen::Vector2f project(const Eigen::Vector3f& v)const;
  Eigen::Vector2f project(const std::vector<float>& v)const;

private:
  Eigen::MatrixXf mat_;
  // ImageType im_;
};

#endif