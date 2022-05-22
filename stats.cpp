#include <algorithm>
#include <numeric>
#include "stats.h"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& vect) {
	Statistics::Stats st;

	if (!(vect.empty()))
	{
            float maxElement = *std::max_element(vect.begin(), vect.end());
	    float minElement = *std::min_element(vect.begin(), vect.end());
	    float average = accumulate(vect.begin(), vect.end(), 0.0) / vect.size();

	    st.avg = average;
	    st.max = maxElement;
	    st.min = minElement;
	}
	return st;
}
