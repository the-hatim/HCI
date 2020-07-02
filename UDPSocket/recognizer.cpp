#include "recognizer.h"
#include <cstdlib>
#include <iostream>


using namespace GRT;
using namespace std;

//VectorFloat start_pos(3);

Recognizer::Recognizer()
{

  trainingData.setNumDimensions(3);
  counter = 1;
  pipeline.setClassifier(DTW());
  pipeline.addPreProcessingModule(LowPassFilter(0.1,15,3,-1,-1));



}
void Recognizer::recordGesture(double x, double y, double z)
{



    //Gesture recording started (starting data)
    /*if (starting == 1)
    {
        start_pos[0] = x;
        start_pos[1] = y;
        start_pos[2] = z;
        sample = start_pos;

        starting = 2;
    }*/
    //starting = 2 means gesture recording is already started;
  //  if (starting == 2)
  //  {
 VectorFloat sample(3);

        sample[0] = x;
        sample[1] = y;
        sample[2] = z;

 trainingSample1.push_back(sample);
      //  starting++;

   // }
     if (starting == 3)
    {
         cout<<"\n"<<counter;

        counter++;
        trainingData.addSample(gestureLabel, trainingSample1);
        trainingSample1.clear();
        //gesture same is complete
        starting = 2;


    }




}

void Recognizer::saveTrainingData()
{
    gestureLabel = gestureLabel + 1;
    counter = 1;
   // sample = start_pos;

}
void Recognizer::saveFile()
{
    if( !trainingData.saveDatasetToFile( "Training1C.GRT" ) ){
          cout << "Failed to save dataset to file!\n";

      }
}

void Recognizer::loadTrainingData()
{
    if (trainingData.load("TrainingData6gesture.GRT"))
        cout<<"Trainging data loaded sucessfully";

    //20% dataset to create a test dataset
   // testData = trainingData.split(80);





   // dtw.enableNullRejection( true );
 //dtw.enableTrimTrainingData(true, 0.1, 90);
    if (!pipeline.train(trainingData)){
        cout<<"failled DTW training";
        
    }

    if (!pipeline.save(("Pipeline6.GRT")))
    {
        cout<<"DTW save failed";
        
    }
    
    /*if (!dtw.load("DTWModel.GRT"))
    {
        cout<<"DTW loaded";
    }
    
    */


}

void Recognizer::recognitionData(double x, double y, double z)
{
    VectorFloat sample(3);

    sample[0] = x;
    sample[1] = y;
    sample[2] = z;
    
    recogniSample.push_back(sample);
}

void Recognizer::Recognize()
{


    if (!pipeline.load("Pipeline6.GRT"))
    {
        cout<<"DTW loaded";
    }
   if (!pipeline.predict(recogniSample))
   {
       cout<<"\n\n\n Failed to predict";
   }
 recogniSample.clear();
   switch(pipeline.getPredictedClassLabel())
   {
    case 1:
       cout<<"\n\n\nYou Just performed a Gesture using your Mobile\n\n";
       cout<<"\n\n-----------------------Bottom ------------------->>>>>>> UP---------------------\n\n";
     //  getchar();
       break;

    case 2:

       cout<<"\n\n\nYou Just performed a Gesture using your Mobile\n\n";
       cout<<"\n\n------------------TOP-------------------->>>>>DOWN----------------------.\n\n";
     system("xdotool getactivewindow windowminimize ");

       //getchar();
       break;

   case 3:
        cout<<"\n\n\nYou Just performed a Gesture using your Mobile\n\n";
       cout<<"\n\nLeft ----------------->>>>>> Right\n\n";
       system(" xdotool  getactivewindow  key Right");


       break;

   case 4:
       cout<<"\n\n\nYou Just performed a Gesture using your Mobile\n\n";
       cout<<"\n\nRight------------------------------>>>>>Left\n\n";

        system(" xdotool getactivewindow  key Left");

        break;

   case 5:
       cout<<"\n\n\nYou Just performed a Gesture using your Mobile\n\n";
       cout<<"\n\nYou just Performed V shape Gesture\n\n";
     //  system(" xdotool getactivewindow windowkill");
      // getchar();
       break;

   case 6: cout<<"\n\n\nYou Just performed a Gesture using your Mobile\n\n";
       cout<<"\n\nYou just Performed A shape Gesture\n\n";
       //system(" xdotool getactivewindow windowkill");
       break;

   default:
       cout<<"NOt able t predict\n\n\n\n";
             //getchar();
   }


}
