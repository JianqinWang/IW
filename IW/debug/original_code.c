// 4-element vector object.
struct SVector4
{
	float m_x, m_y, m_z, m_w;
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
	float* p_temp = new float[num_vectors];

	// Calculate the 3-element dot product, store it in our temp array.
	while( num_vectors >= 0 )
	{
		p_temp[num_vectors] = CalculateDotProduct( &src1[num_vectors], &src2[num_vectors] );
		--num_vectors;
	}

	float biggest_dot_product;
	unsigned int limit = num_vectors;

	// Find the biggest dot product of all the entries.
	for( unsigned int dp = 0; dp < limit; ++dp )
	{
		if( p_temp[dp] > biggest_dot_product )
		{
			biggest_dot_product = p_temp[dp];
		}
	}

	// Find the named parameter so we can set the value.
	for( unsigned int p = 0; p < ShaderFloatParameterTableNumEntries; ++p )
	{
		if( strstr( p_param_name, pShaderFloatParameterTable[p].mp_name ) == 0 )
		{
			// We found a match! Set the value.
			pShaderFloatParameterTable[p].m_value = biggest_dot_product;
		}
	}
}
