

#pragma once

#include <map>
#include <vector>
#include <string>

/*********************************************************************

To add parameters, 
you have to specify the read section and parameter name here.

**********************************************************************/

#define _PARA_SECTION_SHAPE_ALIGNMENT "ShapeAlignment"
#define _PARA_PYRAMID_NUM "Pyramid_Number"
#define _PARA_SCORE_THRESHOLD "Score_threshold"

#define _PARA_SECTION_PLANE_SEGMENTATION_TEMPL "PlaneSegmentation_Templ"
#define _PARA_SECTION_PLANE_SEGMENTATION_QUERY "PlaneSegmentation_Query"
#define _PARA_SEED_NUM "SeedNum"
#define _PARA_VOXEL_RESOL "Voxel Resolution"
#define _PARA_NEIGH_NUM "Neighbour Number"
#define _PARA_DIST_TOL_MERGE_GRIDS "Distance Tolerance For Merge Grids"
#define _PARA_GD_NEIGH_ANG_TOL "Good Neighbour Angle Tolerance"
#define _PARA_ANG_TOL_MERGE_GRIDS "Angle Tolerance For Merge Grids"
#define _PARA_ANG_TOL_MERGE_PLANES "Angle Tolerance For Merge Planes"
#define _PARA_DIST_TOL_MERGE_PLANES "Dist Tolerance For Merge Planes"
#define _PARA_PLANE_DATA_NUM_TOL "Plane Data Number Tolerance"
#define _PARA_LOCAL_NORM_INV_ITER_MAX "Local Normal"
#define _PARA_INPUT_DOWN_SAMPLE_RATE "Input Data Downsample Rate"
#define _PARA_INPUT_DOWN_SAMPLE_RATE_2 "Input Data Downsample Rate2"
#define _PARA_DISABLE_TMP_SEG "Disable Template Segmentation"

#define _PARA_SECTION_ICP "ICP"
#define _PARA_MAX_ITERS "Max Iterations"
#define _PARA_EPS "EPS"

#define _PARA_SECTION_GF "GeometryFilter"
#define _PARA_ERODE_HOLE_ITER "ErodeHoleIter"
#define _PARA_3D_TO_2D_PROJECTION_RESOLUTION "Resolution"

inline void BuildParamNameTree(std::map < std::string, std::vector<std::string>> &ParaNameTree)
{
	ParaNameTree[_PARA_SECTION_SHAPE_ALIGNMENT] = std::vector<std::string>{
		_PARA_PYRAMID_NUM ,
		_PARA_SCORE_THRESHOLD };

	ParaNameTree[_PARA_SECTION_PLANE_SEGMENTATION_TEMPL] = std::vector<std::string>{
		_PARA_DISABLE_TMP_SEG,
		_PARA_SEED_NUM ,
		_PARA_NEIGH_NUM,
		_PARA_DIST_TOL_MERGE_GRIDS,
		_PARA_GD_NEIGH_ANG_TOL, 
		_PARA_ANG_TOL_MERGE_GRIDS,
		_PARA_ANG_TOL_MERGE_PLANES,
		_PARA_DIST_TOL_MERGE_PLANES,
		_PARA_PLANE_DATA_NUM_TOL,
		_PARA_LOCAL_NORM_INV_ITER_MAX };

	ParaNameTree[_PARA_SECTION_PLANE_SEGMENTATION_QUERY] = std::vector<std::string>{
		_PARA_SEED_NUM ,
		_PARA_NEIGH_NUM,
		_PARA_VOXEL_RESOL,
		_PARA_DIST_TOL_MERGE_GRIDS,
		_PARA_GD_NEIGH_ANG_TOL,
		_PARA_ANG_TOL_MERGE_GRIDS,
		_PARA_ANG_TOL_MERGE_PLANES,
		_PARA_DIST_TOL_MERGE_PLANES,
		_PARA_PLANE_DATA_NUM_TOL,
		_PARA_LOCAL_NORM_INV_ITER_MAX,
		_PARA_INPUT_DOWN_SAMPLE_RATE,
		_PARA_INPUT_DOWN_SAMPLE_RATE_2 };

	ParaNameTree[_PARA_SECTION_ICP] = std::vector<std::string>{
		_PARA_MAX_ITERS ,
		_PARA_EPS };


	ParaNameTree[_PARA_SECTION_GF] = std::vector<std::string>{
		_PARA_ERODE_HOLE_ITER,
		_PARA_3D_TO_2D_PROJECTION_RESOLUTION };
}