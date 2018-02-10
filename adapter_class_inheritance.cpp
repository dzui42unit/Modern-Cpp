#include <iostream>

// the class whose interface we want to use in our class

class 	FahrenheitSensor
{
public:
	float	get_fahrenheit_temp(void)
	{
		float t = 544.0;
		return t;
	}
protected:
	void	adjust(void)
	{

	}
};

class 	Sensor
{
public:
	virtual	~Sensor()
	{

	}
	virtual float	get_temperature(void) = 0;
	virtual void	adjust() = 0; 
};

class 	Adapter : public Sensor, private FahrenheitSensor
{
public:
	Adapter()
	{

	}
	float 	get_temperature(void) override
	{
		return ((get_fahrenheit_temp() - 32.0) * 5.0 / 9.0);
	}
	void	adjust(void) override
	{
		FahrenheitSensor::adjust();
	}
};

int		main(void)
{
	Sensor 	*p = new Adapter;
	p->adjust();
	std::cout << "Celsius temperature = " << p->get_temperature() << std::endl;
	return (0);
}