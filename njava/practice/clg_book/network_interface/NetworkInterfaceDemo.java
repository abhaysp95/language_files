// working with NetworkInterface with java

import java.net.*;
import java.util.*;

public class NetworkInterfaceDemo {
	public static void main(String[] args) throws Exception {
		try {
			// check Enumeration in java
			Enumeration intfs = NetworkInterface.getNetworkInterfaces();
			while (intfs.hasMoreElements()) {
				// is this the another way of making object?
				NetworkInterface intf = (NetworkInterface)intfs.nextElement();
				System.out.println("\nInterface: " + intf.getName());
				System.out.println("Display Name: " + intf.getDisplayName());
				// reference to generic enumerator should be parameterized
				Enumeration addresses = intf.getInetAddresses();
				while (addresses.hasMoreElements()) {
					InetAddress addr = (InetAddress)addresses.nextElement();
					System.out.println("Address: " + addr.getHostAddress());
				}
				System.out.println("MTU: " + intf.getMTU());
			}
		}
		catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}
}
