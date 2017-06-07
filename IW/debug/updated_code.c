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
	/* in C, new doesn't work. There was also no delete/free to correspond to the memory
	   allocation
	   We also do not need an array to store all the values, as we only need largest val
	   We change the p_temp float array to simply be a float variable
	   Previously, limit was set to be num_vectors, but at that point in the program
	   num_vectors was already -1, thus it could not execute the 2nd loop.
	   Since we are removing the array, we also no longer need the limit variable
	   In the original code, biggest_dot_product was never initialized. here we will
	   initialize it to be -FLT_MAX. */
	float p_temp;
	float biggest_dot_product = -FLT_MAX;

	// Calculate the 3-element dot product, store it in our temp array.
	/* decrement num_vectors by 1 to avoid invalid array index */
	--num_vectors;
	while( num_vectors >= 0 )
	{
		p_temp = CalculateDotProduct( &src1[num_vectors], &src2[num_vectors] );
		/* compare p_temp to biggest_dot_product, update biggest_dot_product
		   if p_temp is larger*/
		if (p_temp > biggest_dot_product)
			biggest_dot_product = p_temp;
		--num_vectors;
	}

	/* following two lines moved to beginning of function. variable limit would not have
	   a useful value if set here */
	//float biggest_dot_product;
	//unsigned int limit = num_vectors;

	// Find the biggest dot product of all the entries.
	/* this loop is no longer necessary
	for( unsigned int dp = 1; dp < limit; ++dp )
	{
		if( p_temp[dp] > biggest_dot_product )
		{
			biggest_dot_product = p_temp[dp];
		}
	} */

	// Find the named parameter so we can set the value.
	for( unsigned int p = 0; p < ShaderFloatParameterTableNumEntries; ++p )
	{
		/* changing function from strstr to be strcmp */
		if( strcmp( p_param_name, pShaderFloatParameterTable[p].mp_name ) == 0 )
		{
			// We found a match! Set the value.
			pShaderFloatParameterTable[p].m_value = biggest_dot_product;
		}
	}
}
