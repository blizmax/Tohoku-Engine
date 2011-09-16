///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2009 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2005-12-30
// Updated : 2006-11-13
// Licence : This source is under MIT License
// File    : glm/gtx/vector_angle.h
///////////////////////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM core
// - GLM_GTX_quaternion
// - GLM_GTX_epsilon
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glm_gtx_vector_angle
#define glm_gtx_vector_angle

// Dependency:
#include "../glm.hpp"
#include "../gtx/quaternion.hpp"
#include "../gtx/epsilon.hpp"

namespace glm
{
	namespace test{
		void main_gtx_vector_angle();
	}//namespace test

    namespace gtx{
	//! GLM_GTX_vector_angle extension: Compute angle between vectors
    namespace vector_angle
    {
		//! Returns the absolute angle between x and y.
		//! Parameters need to be normalized.
		//! From GLM_GTX_vector_angle extension
		template <typename vecType> 
		typename vecType::value_type angle(
			vecType const & x, 
			vecType const & y);

		//! Returns the oriented angle between x and y 
		//! Parameters need to be normalized.
		//! From GLM_GTX_vector_angle extension.
		template <typename vecType> 
		typename vecType::value_type orientedAngle(
			vecType const & x, 
			vecType const & y);

		//! Returns the orientation of a two vector base from a normal.
		//! Parameters need to be normalized.
		//! From GLM_GTX_vector_angle extension.
		template <typename vecType>
		typename vecType::value_type orientedAngleFromRef(
			vecType const & x,
			vecType const & y,
			detail::tvec3<typename vecType::value_type> const & ref);
    }//namespace vector_angle
    }//namespace gtx
}//namespace glm

#define GLM_GTX_vector_angle namespace gtx::quaternion; using namespace gtx::epsilon; using namespace gtx::vector_angle
#ifndef GLM_GTX_GLOBAL
namespace glm {using GLM_GTX_vector_angle;}
#endif//GLM_GTX_GLOBAL

#include "vector_angle.inl"

#endif//glm_gtx_vector_angle
