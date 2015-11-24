#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double* const read(const int, const string);
void filter(double* const, const int);
void write(const double* const, const int, const string);

int main(){
const int N=237, iterations=15;
const string filenameInitial="noisy.txt";
const string filenameEnd="filtered.txt";
double* const data= read(N,filenameInitial);
for (int i=0;i<iterations;i++) filter(data,N);
write(data,N,filenameEnd);
delete[] data;
return 0;
}

double* const read(const int N, const string filename){
ifstream in(filename.c_str());
double* const data = new double[N];
	for(int i=0;i<N;i++) in >> data[i];
in.close();
return data;
}

void filter(double* const data, const int N){
const double f0=0.1;
double a=f0,b;
	for(int i=0;i<N-1;i++){
		b=data[i];
		data[i]=(a+b+data[i+1])/double(3);
		a=b;
	}
	data[N-1]=(data[N-2]+data[N-1]+f0)/double(3);
}

void write(const double* const data, const int N, const string filename){
ofstream out(filename.c_str());
	for(int i=0;i<N;i++) out << data[i] << endl;
out.close();
}
