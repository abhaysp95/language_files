package com.javasocketprogram;

import java.io.*;
import java.net.*;

public class Server {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(6688);
			Socket s = ss.accept();  // establish connection
			/* s.InputStream() is providing the inputStream as socket 's' is a
			 * ServerSocket(ss.accept()) and if you do readUTF on
			 * DataInputStream it's actually reading from the pipeline created
			 * by ServerSocket maybe */
			DataInputStream dis = new DataInputStream(s.getInputStream());
			String str = dis.readUTF().toString();
			System.out.println(str);

			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			dos.writeUTF("hello client");
			dos.flush();
			ss.close();
		}
		catch (IOException ie) {
			System.out.println("some ioexception: " + ie.getMessage());
		}
	}
}