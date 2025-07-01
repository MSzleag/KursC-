#include <iostream>
using namespace std;

const float PI = 3.141592f;

float Cube(float x) {

	return x * x * x;
}

float Volume(float r) {

	float v = 0.0f;
	v = (4.0f/3.0f) * PI * Cube(r);

	return v;
}

int main() {

	float r = 0.0f;

	cout << "Prosze podac promien Kuli w cm: ";
	cin >> r;

	cout << endl << "Objetosc to: " << Volume(r) << "cm^3" << endl;

	return 0;
}