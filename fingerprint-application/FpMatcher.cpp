#include "FpMatcher.hpp"
#include "OfDetector.hpp"

FpMatcher::FpMatcher() {
	fpSegmentator = FpSegmentator();
	fpEnhancer = FpEnhancer();
	mnExtractor = MnExtractor();
	mnMatcher = MnMatcher();
}

//----------------------------------------------------------------------
double FpMatcher::match(const cv::Mat& fpImg1, const cv::Mat& fpImg2) { 

   cout << "Stub: matching fpImg1 with fpImg2" << endl; 
   
   cv::Mat fpExtracted1 = extractFingerprint(fpImg1);
   cv::Mat fpExtracted2 = extractFingerprint(fpImg2);

   return mnMatcher.match(fpImg1, fpImg2);
}
cv::Mat& FpMatcher::extractFingerprint(const cv::Mat & fingerprintImg)
{
	cv::Mat segmented = fpSegmentator.segment(fingerprintImg); // Crop fingerprint area
	cv::Mat enhanced = fpEnhancer.enhance(segmented); // Estimate ridge orientation
	throw std::logic_error("Not implemented"); 
	// Obtain skeleton image
}
//----------------------------------------------------------------------