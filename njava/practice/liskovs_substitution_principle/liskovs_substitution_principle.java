/* What is Liskov's Substitution Principle

   If a program is using a base class, then the reference to the base class can
   be replaced with a derived class without affecting the functionality of the
   program.

   Intent -> Derived types must be completely able to substitute for their base
   type
*/

import java.util.Date;
import java.util.Calendar;
import java.util.List;
import java.util.ArrayList;

interface IDatabase {
	public void addToDatabase();
}

interface IBooking {
	// only members can perform booking for court
	public void makeBooking();
}

// Old block(before trying to add makeBooking() to Enquiry)
/*abstract class Member {
	String name;
	String memberType;
	Date mStartDate;
	Date mEndDate;

	public Member(String name) {
		this.name = name;
	}

	public abstract void addToDatabase();

	// only members can do court booking
	public abstract void makeBooking();
}*/

// no need from Member now to be abstract
abstract class Member implements IDatabase, IBooking {
	String name;
	String memberType;
	Date mStartDate;
	Date mEndDate;

	public Member(String name) {
		this.name = name;
	}

	public abstract void addToDatabase();
	public abstract void makeBooking();
}

class LifeTimeMember extends Member {
	public LifeTimeMember(String name, Date mStart) {
		super(name);
		this.memberType = "Lifetime";
		// when this will not found it here, it'll automatically refer to super
		this.mStartDate = mStart;
		Calendar c = Calendar.getInstance();
		c.setTime(this.mStartDate);
		c.add(Calendar.YEAR, 70);
		this.mEndDate = c.getTime();  // 70 years from mStartDate
	}

	@Override
	public void addToDatabase() {
		// Logic to add this customer into DB
		System.out.println("Added the lifetime member info into DB");
	}

	@Override
	public void makeBooking() {
		System.out.println("Court booked for lifetime member");
	}
}

class AnnualMember extends Member {
	public AnnualMember(String name, Date mStart) {
		super(name);
		this.memberType = "Annual";
		this.mStartDate = mStart;
		Calendar c = Calendar.getInstance();
		c.setTime(mStartDate);
		c.add(Calendar.YEAR, 1);
		this.mEndDate = c.getTime();
	}

	@Override
	public void addToDatabase() {
		System.out.println("Added the annual member info into DB");
	}

	@Override
	public void makeBooking() {
		System.out.println("Court booked for lifetime member");
	}
}

//class Enquiry extends Member {
class Enquiry implements IDatabase {

	String name;
	public Enquiry(String name) {
		this.name = name;
	}

	@Override
	public void addToDatabase() {
		System.out.println("Added the enquiry info into DB");
	}

	// but enquiry method can't have makeBooking() because it's not member, so
	// can't do court booking, but abstract class is making it compulsory

	// One way is to throw Exception
	/*public void makeBooking() throws Exception {
		throw new Exception("Can't do booking of non-member");
	}*/
	// but it'll not be able to substitute since it's properly implementing the
	// makeBooking() method, so Liskov's Substitution Principle

	/* One could say that, we can just print the statement for not booking in
	 * makeBooking() and it'll not be voilation of Liskov's Substitution
	 * Principle per say, but if you see logically makeBooking() here then also
	 * is not doing any booking which is the voilation of Liskov's Substitution
	 * Principle */

	/* So, we learned from this behaviour that Enquiry is not actually a Member
	 * in reality although it has certain thing common */

	/* So, one thing we could is create another interface for adding into
	 * Database, and then Enquiry should extend that interface not Member */
}

class MainForMember {
	public static void main(String[] args) {
		//List<Member> myList = new ArrayList<Member>();

		//myList.add(new LifeTimeMember("Tom Cruise", new Date()));
		//myList.add(new AnnualMember("Brad Pitt", new Date()));
		//myList.add(new Enquiry("Morgage Freeman"));

		//for (Member m: myList) {
			 //invoke addToDatabase for every member
			//m.addToDatabase();
			//m.makeBooking();
		//}

		List<IDatabase> myList = new ArrayList<IDatabase>();
		List<IBooking> myList1 = new ArrayList<IBooking>();
		Member lt = new LifeTimeMember("Tom Cruise", new Date());
		Member at = new AnnualMember("Brad Pitt", new Date());
		myList.add(lt);
		myList.add(at);
		myList.add(new Enquiry("Morgage Freeman"));
		for (IDatabase m: myList) {
			m.addToDatabase();
		}
		myList1.add(lt);
		myList1.add(at);
		for (IBooking m: myList1) {
			m.makeBooking();
		}
	}
}


// Question -> Now that Member is not itself abstract but implementing
// Interface, will it's child class have to necessarily have method for all the
// signatures of implemented interface of parent?
// Answer -> A non-abstract class must implement the whole interface and the
// child/s will inherit this implementation


// Question -> Member is not abstract and does not override abstract method
// makeBooking() in Member

// Question -> For the above error, It says class needs to be abstract to
// define abstract methods(was class may not be abstract and can have abstract
// method was an old feature and removed)?
// Answer -> Okay, so yeah, this was old behaviour and what C++ do(in it you
// can have virtual functions in normal classes)

// Question -> Now, overriding like "addToDatabase()" is working like? Child is
// overriding it from Member which have given the abstract signature, now this
// signature is also provided in IDatabase interface, how is the signature in
// IDatabase and in Member are related or different?
