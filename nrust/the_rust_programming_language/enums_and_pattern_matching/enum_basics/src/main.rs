enum IpAddrKind {
    V4,
    V6,
}

fn route(_ip_kind: IpAddrKind) {}

struct IpAddrStruct {
    kind: IpAddrKind,
    data: String,
}
// We can define above concept in much more concise way with enum

enum IpAddr {
    V4(String),
    V6(String),
}
// Another benefit of using enum over struct will be that we can use different types and amount of associated data with each varient

enum IpAddrRedefine {
    V4(u8, u8, u8, u8),
    V6(String),
}

// standard library defines IpAddr as, it has the exact enum and variants in that we've defined and used, but it embeds the address data inside the variants in the form of two different structs, which are defined differently from each variant;
struct Ipv4Addr {
    // --snip--
}

struct Ipv6Addr {
    // --snip--
}

enum IpAddrStd {
    V4(Ipv4Addr),
    V6(Ipv6Addr),
}

enum Message {
    Quit,  // no data associated
    Move {x: i32, y: i32},  // includes an anonymous struct
    Write(String),  // includes a single string
    ChangeColor(i32, i32, i32),  // includes 3 i32 values
}

impl Message {
    fn call(&self) {
        // method body would be defined here
    }
}

fn main() {
    let _four = IpAddrKind::V4;
    let _six = IpAddrKind::V6;

    route(IpAddrKind::V4);
    route(IpAddrKind::V6);

    let _home = IpAddrStruct {
        kind: IpAddrKind::V4,
        data: String::from("127.0.0.1"),
    };
    let _loopback = IpAddrStruct {
        kind: IpAddrKind::V6,
        data: String::from("::1"),
    };

    let _home1 = IpAddr::V4(String::from("127.0.0.1"));
    let _loopback1 = IpAddr::V6(String::from("::1"));

    let _home2 = IpAddrRedefine::V4(127, 0, 0, 1);
    let _loopback2 = IpAddrRedefine::V6(String::from("::1"));

    let m = Message::Write(String::from("Hello"));
    m.call();
}
