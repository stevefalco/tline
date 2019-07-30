#ifndef __cableTypes__
#define __cableTypes__

#define USE_FEET		1
#define USE_METERS		2

typedef struct {
	double frequency;
	double attenuation;
} ATTENUATION;

typedef struct {
		const char	*name;
		ATTENUATION	*attenuation;
		double		velocityFactor;
		double		impedance;
} CABLE_PROPERTIES;

class cableTypes
{
	public:
		cableTypes( void );

		CABLE_PROPERTIES * findCable(
				const char		*name
				);

		double findAtten(
				int			units,
				CABLE_PROPERTIES	*cp,
				double			frequency
				);
};

#endif // __cableTypes__
