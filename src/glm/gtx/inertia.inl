///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2009 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2006-04-21
// Updated : 2006-12-06
// Licence : This source is under MIT License
// File    : glm/gtx/inertia.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace glm{
namespace gtx{
namespace inertia{

    template <typename T>
    inline detail::tmat3x3<T> boxInertia3(
		const T Mass, 
		const detail::tvec3<T>& Scale)
    {
	    detail::tmat3x3<T> Result(T(1));
	    Result[0][0] = (Scale.y * Scale.y + Scale.z * Scale.z) * Mass / T(12);
	    Result[1][1] = (Scale.x * Scale.x + Scale.z * Scale.z) * Mass / T(12);
	    Result[2][2] = (Scale.x * Scale.x + Scale.y * Scale.y) * Mass / T(12);
        return Result;
    }

    template <typename T>
    inline detail::tmat4x4<T> boxInertia4(
		const T Mass, 
		const detail::tvec3<T>& Scale)
    {
	    detail::tmat4x4<T> Result(T(1));
	    Result[0][0] = (Scale.y * Scale.y + Scale.z * Scale.z) * Mass / T(12);
	    Result[1][1] = (Scale.x * Scale.x + Scale.z * Scale.z) * Mass / T(12);
	    Result[2][2] = (Scale.x * Scale.x + Scale.y * Scale.y) * Mass / T(12);
        return Result;
    }

    template <typename T>
    inline detail::tmat3x3<T> diskInertia3(
		const T Mass, 
		const T Radius)
    {
        T a = Mass * Radius * Radius / T(2);
        detail::tmat3x3<T> Result(a);
        Result[2][2] *= T(2);
        return Result;
    }

    template <typename T>
    inline detail::tmat4x4<T> diskInertia4(
		const T Mass, 
		const T Radius)
    {
        T a = Mass * Radius * Radius / T(2);
        detail::tmat4x4<T> Result(a);
        Result[2][2] *= T(2);
        Result[3][3] = T(1);
        return Result;
    }

    template <typename T>
    inline detail::tmat3x3<T> ballInertia3(
		const T Mass, 
		const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(5);
        return detail::tmat3x3<T>(a);
    }

    template <typename T>
    inline detail::tmat4x4<T> ballInertia4(
		const T Mass, 
		const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(5);
        detail::tmat4x4<T> Result(a);
        Result[3][3] = T(1);
        return Result;
    }

    template <typename T>
    inline detail::tmat3x3<T> sphereInertia3(
		const T Mass, 
		const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(3);
        return detail::tmat3x3<T>(a);
    }

    template <typename T>
    inline detail::tmat4x4<T> sphereInertia4(
		const T Mass, 
		const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(3);
        detail::tmat4x4<T> Result(a);
        Result[3][3] = T(1);
        return Result;
    }

}//namespace inertia
}//namespace gtx
}//namespace glm
