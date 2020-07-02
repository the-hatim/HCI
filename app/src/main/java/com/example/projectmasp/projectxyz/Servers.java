package com.example.projectmasp.projectxyz;

import android.content.Context;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.Socket;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link Servers.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link Servers#newInstance} factory method to
 * create an instance of this fragment.
 */
public class Servers extends Fragment
{
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private OnFragmentInteractionListener mListener;

    public Servers()
    {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment Servers.
     */
    // TODO: Rename and change types and number of parameters
    public static Servers newInstance(String param1, String param2)
    {
        Servers fragment = new Servers();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        if (getArguments() != null)
        {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState)
    {
        // Inflate the layout for this fragment
        final View view = inflater.inflate(R.layout.fragment_servers, container, false);

        //testBtn = (Button) view.findViewById(R.id.testBtn);

        //testView = (TextView) view.findViewById(R.id.testBtn);
        //RetrieveFeedTask rft = new RetrieveFeedTask();
        //testView = (TextView) findViewById(R.id.info_text);
        //rft.execute(MainActivity.getAccel());
        //testView.setText("test");
        return inflater.inflate(R.layout.fragment_servers, container, false);
    }

    public class RetrieveFeedTask extends AsyncTask<String, Void, String>
    {

        @Override
        protected String doInBackground(String... params)
        {
            System.out.println("Inside Btn click try...");
            DatagramSocket sock = null;
            DatagramPacket udpPacket;
            String stringToSend = params[0];
            String udpmessage = "UDP packet test";
            try
            {
                sock = new DatagramSocket(2050);
                Log.d("server socket", "Created");
                InetAddress serverAdd = InetAddress.getByName("192.168.1.7");


                udpPacket = new DatagramPacket(stringToSend.getBytes(),stringToSend.length(),serverAdd,2050);

                Log.d("Test_socket-connection","Reading...");

                sock.send(udpPacket);
                //test = br.readLine();
              //  System.out.println(test);
                Log.d("Test_socket-connection","Printing to device...");
                //sock.close();
               return udpmessage;
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            finally {
                if (sock != null){
                    sock.close();
                }
            }
            return null;
        }

        protected void onPostExecute(String s)
        {
            super.onPostExecute(s);

        }

    }
    // TODO: Rename method, update argument and hook method into UI event
    public void onButtonPressed(Uri uri)
    {
        if (mListener != null)
        {
            mListener.onFragmentInteraction(uri);
        }
    }

    @Override
    public void onAttach(Context context)
    {
        super.onAttach(context);
        if (context instanceof OnFragmentInteractionListener)
        {
            mListener = (OnFragmentInteractionListener) context;
        } else
        {
            throw new RuntimeException(context.toString()
                    + " must implement OnFragmentInteractionListener");
        }
    }

    @Override
    public void onDetach()
    {
        super.onDetach();
        mListener = null;
    }

    /**
     * This interface must be implemented by activities that contain this
     * fragment to allow an interaction in this fragment to be communicated
     * to the activity and potentially other fragments contained in that
     * activity.
     * <p>
     * See the Android Training lesson <a href=
     * "http://developer.android.com/training/basics/fragments/communicating.html"
     * >Communicating with Other Fragments</a> for more information.
     */
    public interface OnFragmentInteractionListener
    {
        // TODO: Update argument type and name
        void onFragmentInteraction(Uri uri);
    }

}

