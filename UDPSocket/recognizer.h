#ifndef RECOGNIZER_H
#define RECOGNIZER_H
#include"mouseEvent.h"
#include "GRT/GRT.h"

using namespace GRT;
class Recognizer
{

private:

    UINT gestureLabel = 1;
    MatrixFloat trainingSample1;
    GestureRecognitionPipeline pipeline;
    DTW dtw;

    MatrixFloat recogniSample;



public:
      TimeSeriesClassificationData trainingData;
      TimeSeriesClassificationData testData, recogData;
    UINT starting = 0;

    Recognizer();

    void recordGesture(double x, double y, double z);
    void saveTrainingData();
    void loadTrainingData();
    void saveFile();
    void recognitionData(double x, double y, double z);
    void Recognize();

    int counter;

  };

#endif // RECOGNIZER_H
