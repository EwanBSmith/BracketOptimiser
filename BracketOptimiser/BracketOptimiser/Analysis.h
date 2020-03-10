#include "Bracket.h"
#include <cmath>

#define PI 3.14159265358979323846

class analysisResults {
public:
	double shearStress;
	double bearingStress;
	double tensileStress;
};

class Analysis {
public:
	analysisResults runAnalysis(Bracket bracketForAnalysis, double load) {
		analysisResults results;

		double bearingArea = 0.5 * PI * bracketForAnalysis.holeDiameter * bracketForAnalysis.thickness;
		double tensileArea = bracketForAnalysis.thickness * ((2*bracketForAnalysis.lugRadius) - bracketForAnalysis.holeDiameter);
		double shearArea = (bracketForAnalysis.lugRadius-((bracketForAnalysis.holeDiameter/2)*cos(0.698132)))*2 * bracketForAnalysis.thickness;

		results.bearingStress = load / bearingArea;
		results.tensileStress = load / tensileArea;
		results.shearStress = load / shearArea;

		return results;
	}
};