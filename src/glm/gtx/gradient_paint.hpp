///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2009 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2009-03-06
// Updated : 2009-03-09
// Licence : This source is under MIT License
// File    : glm/gtx/gradient_paint.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM core
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef glm_gtx_gradient_paint
#define glm_gtx_gradient_paint

// Dependency:
#include "../glm.hpp"
#include "../gtx/optimum_pow.hpp"

namespace glm
{
	namespace test{
		void main_gtx_gradient_paint();
	}//namespace test

	namespace gtx{
	//! GLM_GTX_gradient_paint extension: Compute a radient gradient according section OpenVG 1.1 specifications, 9.3.2 Radial Gradients
	namespace gradient_paint
	{
		using namespace gtx::optimum_pow;

		template <typename valType>
		valType radialGradient(
			glm::detail::tvec2<valType> const & Center,
			valType const & Radius,
			glm::detail::tvec2<valType> const & Focal,
			glm::detail::tvec2<valType> const & Position);

		template <typename valType>
		valType linearGradient(
			glm::detail::tvec2<valType> const & Point0,
			glm::detail::tvec2<valType> const & Point1,
			glm::detail::tvec2<valType> const & Position);

	}//namespace gradient_paint
    }//namespace gtx
}//namespace glm

#define GLM_GTX_gradient_paint namespace gtx::gradient_paint
#ifndef GLM_GTX_GLOBAL
namespace glm {using GLM_GTX_gradient_paint;}
#endif//GLM_GTX_GLOBAL

#include "gradient_paint.inl"

#endif//glm_gtx_gradient_paint
