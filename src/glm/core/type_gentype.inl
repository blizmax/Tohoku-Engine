///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2009 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2008-10-05
// Updated : 2008-10-05
// Licence : This source is under MIT License
// File    : glm/core/type_gentype.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace glm{
namespace detail{

/////////////////////////////////
// Static functions

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::size_type genType<vT, cT, rT, pT>::col_size()
{
	return cT;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::size_type genType<vT, cT, rT, pT>::row_size()
{
	return rT;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::size_type genType<vT, cT, rT, pT>::value_size()
{
	return rT * cT;
}

template <typename vT, uint cT, uint rT, profile pT>
bool genType<vT, cT, rT, pT>::is_scalar()
{
	return rT == 1 && cT == 1;
}

template <typename vT, uint cT, uint rT, profile pT>
bool genType<vT, cT, rT, pT>::is_vector()
{
	return rT == 1;
}

template <typename vT, uint cT, uint rT, profile pT>
bool genType<vT, cT, rT, pT>::is_matrix()
{
	return rT != 1;
}

/////////////////////////////////
// Constructor

template <typename vT, uint cT, uint rT, profile pT>
genType<vT, cT, rT, pT>::genType()
{
	memset(&this->value, 0, cT * rT * sizeof(vT));
}

template <typename vT, uint cT, uint rT, profile pT>
genType<vT, cT, rT, pT>::genType
(
	typename genType<vT, cT, rT, pT>::class_type const & m
)
{
	for
	(
		typename genType<vT, cT, rT, pT>::size_type i = typename genType<vT, cT, rT, pT>::size_type(0);
		i < genType<vT, cT, rT, pT>::col_size();
		++i
	)
	{
		this->value[i] = m[i];
	}
}

template <typename vT, uint cT, uint rT, profile pT>
genType<vT, cT, rT, pT>::genType
(
	typename genType<vT, cT, rT, pT>::value_type const & x
)
{
	if(rT == 1) // vector
	{
		for
		(
			typename genType<vT, cT, rT, pT>::size_type i = typename genType<vT, cT, rT, pT>::size_type(0);
			i < genType<vT, cT, rT, pT>::col_size();
			++i
		)
		{
			this->value[i][rT] = x;
		}
	}
	else // matrix
	{
		memset(&this->value, 0, cT * rT * sizeof(vT));

		typename genType<vT, cT, rT, pT>::size_type stop = cT < rT ? cT : rT;

		for
		(
			typename genType<vT, cT, rT, pT>::size_type i = typename genType<vT, cT, rT, pT>::size_type(0);
			i < stop;
			++i
		)
		{
			this->value[i][i] = x;
		}
	}
}

template <typename vT, uint cT, uint rT, profile pT>
genType<vT, cT, rT, pT>::genType
(
	typename genType<vT, cT, rT, pT>::value_type const * const x
)
{
	memcpy(&this->value, &x.value, cT * rT * sizeof(vT));
}

template <typename vT, uint cT, uint rT, profile pT>
genType<vT, cT, rT, pT>::genType
(
	typename genType<vT, cT, rT, pT>::col_type const * const x
)
{
	for
	(
		typename genType<vT, cT, rT, pT>::size_type i = typename genType<vT, cT, rT, pT>::size_type(0);
		i < genType<vT, cT, rT, pT>::col_size();
		++i
	)
	{
		this->value[i] = x[i];
	}
}

template <typename vT, uint cT, uint rT, profile pT>
template <typename vU, uint cU, uint rU, profile pU>
genType<vT, cT, rT, pT>::genType
(
	genType<vU, cU, rU, pU> const & m
)
{
	for
	(
		typename genType<vT, cT, rT, pT>::size_type i = typename genType<vT, cT, rT, pT>::size_type(0);
		i < genType<vT, cT, rT, pT>::col_size();
		++i
	)
	{
		this->value[i] = genType<vT, cT, rT, pT>(m[i]);
	}
}

//////////////////////////////////////
// Accesses

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::col_type& genType<vT, cT, rT, pT>::operator[]
(
	typename genType<vT, cT, rT, pT>::size_type i
)
{
	return this->value[i];
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::col_type const & genType<vT, cT, rT, pT>::operator[]
(
	typename genType<vT, cT, rT, pT>::size_type i
) const
{
	return this->value[i];
}

//////////////////////////////////////
// Unary updatable operators

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator= 
(
	typename genType<vT, cT, rT, pT>::class_type const & x
)
{
	memcpy(&this->value, &x.value, cT * rT * sizeof(vT));
	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator+= 
(
	typename genType<vT, cT, rT, pT>::value_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] += x;

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator+= 
(
	typename genType<vT, cT, rT, pT>::class_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] += x[j][i];

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator-= 
(
	typename genType<vT, cT, rT, pT>::value_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] -= x;

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator-= 
(
	typename genType<vT, cT, rT, pT>::class_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] -= x[j][i];

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator*= 
(
	typename genType<vT, cT, rT, pT>::value_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] *= x;

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator*= 
(
	typename genType<vT, cT, rT, pT>::class_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] *= x[j][i];

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator/= 
(
	typename genType<vT, cT, rT, pT>::value_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] /= x;

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator/= 
(
	typename genType<vT, cT, rT, pT>::class_type const & x
)
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = x.col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = x.row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		this->value[j][i] /= x[j][i];

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator++ ()
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		++this->value[j][i];

	return *this;
}

template <typename vT, uint cT, uint rT, profile pT>
typename genType<vT, cT, rT, pT>::class_type& genType<vT, cT, rT, pT>::operator-- ()
{
	typename genType<vT, cT, rT, pT>::size_type stop_col = col_size();
	typename genType<vT, cT, rT, pT>::size_type stop_row = row_size();

	for(typename genType<vT, cT, rT, pT>::size_type j = 0; j < stop_col; ++j)
	for(typename genType<vT, cT, rT, pT>::size_type i = 0; i < stop_row; ++i)
		--this->value[j][i];

	return *this;
}

} //namespace detail
} //namespace glm
