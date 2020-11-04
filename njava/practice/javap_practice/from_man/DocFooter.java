/* There are several flags and arguments which can be passed with javap command,
   For more details, see "man javap"  (obviously, saying for Unix(linux) systems)
   Also, there's '--help' flag of javap, if you don't want to open man */

/* The following example is taken from man page of javap */

import java.awt.*;
import java.applet.*;

public class DocFooter extends Applet {
	String date;
	String email;

	public void init() {
		resize(500, 100);
		date = getParameter("LAST_UPDATED");
		email = getParameter("EMAIL");
	}

	public void paint(Graphics g) {
		g.drawString(date + " by", 100, 15);
		g.drawString(email, 290, 15);
	}
}

/* Warning: Applet is now deprecated, I think from Java9 and onwards, although
 * you can still use them but its not recommended */
