/** Help file */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Help {
	String helpFile;

	public Help(String fname) {
		this.helpFile = fname;
	}

	public boolean helpOn(String onWhat) {
		int ch;
		String topic, info;

		try (BufferedReader br = new BufferedReader(new FileReader(this.helpFile))) {
			do {
				// read characters util a # is found
				ch = br.read();
				if (ch == '#') {
					topic = br.readLine();
					//System.out.println("Got topic: " + topic);
					if (onWhat.compareTo(topic) == 0) {
						do {
							info = br.readLine();
							if (info != null) {
								System.out.println(info);
							}
						} while ((info != null)  && (info.compareTo(" ") != 0));
						// no extra whitespace should be in help file
						return true;
					}
				}
			} while (ch != -1);
		}
		catch (IOException ie) {
			System.out.println("Error accessing in file: " + ie);
			return false;
		}
		return false;  // topic not found
	}

	// get help topic
	public String getSelection() {
		String topic = "";
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter topic: ");
		try {
			topic = br.readLine();
		}
		catch (IOException ie) {
			System.out.println("Error reading console");
		}
		return topic;
	}
}

public class FileHelp {
	public static void main(String[] args) {
		try {
			Help helpObj = new Help(args[0]);
			System.out.println("Try help system." +
					"Enter 'stop' to end");
			String topic;
			do {
				topic = helpObj.getSelection();
				if (!helpObj.helpOn(topic)) {
					System.out.println("Topic not found\n");
				}
			} while(topic.compareTo("stop") != 0);
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Provide the help file");
		}
	}
}
