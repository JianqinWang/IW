/* new comments will be added using /* and */

// 4-element vector object.
struct SVector4
{
	/* remove variable m_w */
	float m_x, m_y, m_z;
};

// Float-based shader parameter object.
struct SShaderFloatParameter
{
	float m_value;
	char* mp_name;
};

// The table of float-based shader parameters -
// typically 500+ entries - no duplicate names.
extern SShaderFloatParameter *pShaderFloatParameterTable;
extern unsigned int ShaderFloatParameterTableNumEntries;

float CalculateDotProduct( SVector4* src1, SVector4* src2 )
{
	// Calculate the 3-element dot product of two input vectors, and return it.
	float result = src1->m_x * src2->m_x + src1->m_y * src2->m_y + src1->m_z * src2->m_z;
	return result;
}

void SetVectorParameterAsLargestDP( char* p_param_name, SVector4* src1, SVector4* src2, int num_vectors )
{
	// This function iterates over the incoming vectors and calculates
	// the 3-element dot product between each pair of vectors src1[n] and
	// src2[n]. The largest dot product calculated should be stored in the
	// table entry for the specific shader parameter which matches the
	// supplied name.

	// Create a temporary array for intermediate results.
	// float* p_temp = new float[num_vectors];
	/* in C, new doesn't work. */
	float p_temp[num_vectors];
	float biggest_dot_product;
	unsigned int limit = num_vectors;

	// Calculate the 3-element dot product, store it in our temp array.
	/* decrement num_vectors by 1 to avoid invalid array index */
	--num_vectors;
	while( num_vectors >= 0 )
	{
		p_temp[num_vectors] = CalculateDotProduct( &src1[num_vectors], &src2[num_vectors] );
		--num_vectors;
	}

	/* following two lines moved to beginning of function. variable limit would not have
	   a useful value if set here */
	//float biggest_dot_product;
	//unsigned int limit = num_vectors;

	// Find the biggest dot product of all the entries.
	/* initialize variable biggest_dot_product to be first val in array*/
	biggest_dot_product = p_temp[0];
	/* change initial dp val to 1 because p_temp[0] will never be > than p_temp[0] */
	for( unsigned int dp = 1; dp < limit; ++dp )
	{
		if( p_temp[dp] > biggest_dot_product )
		{
			biggest_dot_product = p_temp[dp];
		}
	}

	// Find the named parameter so we can set the value.
	for( unsigned int p = 0; p < ShaderFloatParameterTableNumEntries; ++p )
	{
		/* changing function to be strcmp */
		if( strcmp( p_param_name, pShaderFloatParameterTable[p].mp_name ) == 0 )
		{
			// We found a match! Set the value.
			pShaderFloatParameterTable[p].m_value = biggest_dot_product;
		}
	}
}
