var userOne = {
	email: 'thisisgood@xyz.com',
	name: 'thisisgood',
	login() {
		console.log(this.name + " has logged in.");
	},
	logout() {
		console.log(this.name + " has logged out.");
	}
}

console.log(userOne);
console.log(userOne.email);
userOne.login();
userOne.logout();

userOne.name = 'thisistoogood';
console.log(userOne.name);

/* New ES6 way */
class User {
	constructor(name, email) {
		this.name = name;
		this.email = email;
		this.score = 0;
	}
	login() {
		console.log(this.name + " has logged in.");
		return this;
	}
	logout() {
		console.log(this.name + " has logged out.");
		return this;
	}
	updateScore() {
		this.score++;
		return this; // helps in method chaining
	}
};

let user1 = new User('this', 'this@xyz.com');
let user2 = new User('that', 'that@xyz.com');
user1.login();
user2.logout();

user2.logout().updateScore().login().updateScore()
console.log(user2.score);

class Admin extends User {
	deleteUser(user) {
		users = users.filter(u => {
			return u.email != user.email;
		});
	}
};

let admin = new Admin("admin", "admin@xyz.com");
let users = [ user1, user2, admin ];
console.log(users);

admin.deleteUser(user2);
console.log(users);


/* old way */
function UserOld(name, email) {
	this.name = name;
	this.email = email;
	this.online = false;
	// constructor should not have methods, use prototype
	/*this.login = function () {
		console.log(this.email + " has logged in");
	}*/
};

/* Constructor can have prototype property not instances(they have __proto__ property) */
UserOld.prototype.login = function() {
	this.online = true;
	console.log(this.email + " has logged in");
}

UserOld.prototype.logout = function() {
	this.online = false;
	console.log(this.email + " has logged out");
}

let user3 = new UserOld("user3", "user3@xyz.com");
let user4 = new UserOld("user4", "user4@xyz.com");
user3.login();
user4.logout();

console.log(user3.__proto__);

function OldAdmin(...args) {
	UserOld.apply(this, args);
	this.role = "old admin";
}

OldAdmin.prototype = Object.create(User.prototype);

let oldAdmin = new OldAdmin("oldAdmin", "oldAdmin@xyz.com");
console.log(oldAdmin.__proto__);

OldUsers = [ user3, user4, oldAdmin ];
console.log(OldUsers);

OldAdmin.prototype.deleteUser = function(user) {
	OldUsers = OldUsers.filter(u => {
		return u.email != user.email;
	});
}
console.log(oldAdmin.__proto__);

OldAdmin.prototype.login = function() {
	console.log(this.email + " has logged in, called from OldAdmin");
}

oldAdmin.deleteUser(user4);
oldAdmin.login();
console.log(OldUsers);
