package com.javasocketprogram;

import java.net.*;
import java.io.*;

public class Client {
	public static void main(String[] args) {
		try {
			// now with the help of IP and port, this client is connecting with
			// same pipeline which server opened on that same port number
			Socket s = new Socket("localhost", 6688);
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			dos.writeUTF("hello server");
			dos.flush();
			dos.close();
			s.close();
		}
		catch (UnknownHostException uhe) {
			System.out.println("some exception: " + uhe.getMessage());
		}
		catch (IOException ie) {
			System.out.println("some ioexception: " + ie.getMessage());
		}
	}
}