#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){ 
    int sample_rate = 44100; // samples per second, select value which provides good quality sound  
    double duration = 10; // how long [seconds] it will sound 
    int n_samples = sample_rate * duration; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
                        // - how many samples are there altogether? What type should this variable be? 
    double dt = (double)1 / sample_rate; // time between samples 
	int* waveform = new int[n_samples]; // creates the array 
    int frequency = 600;// pitch of the sound 
    int volume = 5500;// 6000 is loud enough 
    double tone_length = 0.5; 

    for (int i_sample = 0; i_sample < n_samples ; i_sample++){  
       // if using array 
        int per = (int)((dt * i_sample)/tone_length);
        frequency = (per%2==0) ? 9000 : 6000;
        //cout << "time ="<<dt * i_sample <<"  "<< frequency<<std::endl; //waveform[i_sample] << endl; 
        waveform[i_sample] = volume* sin(2 * M_PI * frequency * dt * i_sample);// 
       //cout an be used here to check values of "waveform"
      
    }     
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
    MakeWavFromInt("siren.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
    delete[] (waveform); //if using array  
    return 0; 
} 
//make array depending how long the duration is. every second change between one frequency to the next so one second is one then two sencond is the other and so on.
//make a for loop that goes through the array and changes the frequency every second







