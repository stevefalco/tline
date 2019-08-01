#ifndef __cableTypes__
#define __cableTypes__

// WARNING: These assigments must match the order in the GUI.
#define USE_FEET		0
#define USE_METERS		1

typedef struct {
	double frequency;
	double attenuation;
} ATTENUATION;

typedef struct {
		const char	*name;
		ATTENUATION	*attenuation;
		double		velocityFactor;
		double		impedance;
		double		maximumVoltage;
} CABLE_PROPERTIES;

class cableTypes
{
	public:
		cableTypes( void );

		CABLE_PROPERTIES * findCable(
				const char		*name
				);

		double findAtten(
				CABLE_PROPERTIES	*cp,
				double			frequency
				);
};

#endif // __cableTypes__
