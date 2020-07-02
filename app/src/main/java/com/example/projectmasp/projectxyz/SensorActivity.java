package com.example.projectmasp.projectxyz;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

import static android.content.Context.SENSOR_SERVICE;


public class SensorActivity extends Activity implements SensorEventListener
{
    private final SensorManager mSensorManager;
    private final Sensor mAccelerometer;
    TextView info_text;

    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
    }
    public SensorActivity()
    {
        mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        mAccelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        info_text = (TextView) findViewById(R.id.info_text);
    }


    protected void onResume()
    {
        super.onResume();
        mSensorManager.registerListener(this, mAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
    }

    protected void onPause()
    {
        super.onPause();
        mSensorManager.unregisterListener(this);
    }

    public void onAccuracyChanged(Sensor sensor, int accuracy)
    {
    }

    public void onSensorChanged(SensorEvent event)
    {
        //Right in here is where you put code to read the current sensor values and
        //update any views you might have that are displaying the sensor information
        //You'd get accelerometer values like this:
        if (event.sensor.getType() != Sensor.TYPE_ACCELEROMETER)
            return;

        float x = event.values[0];
        float y = event.values[1];
        float z = event.values[2];

        double total = Math.sqrt(x*x + y*y + z*z);

        info_text.setText("" + total);

    }
}