use std::{io, cmp::Ordering};


/* fn show_files() -> io::Result<()> {

    let mut v = vec![];

    fn cmp_by_timestamp_then_name(a: &FileInfo, b: &FileInfo) -> Ordering {
        a.timestamp.cmp(&b.timestamp)
            .reverse()
            .then(a.path.cmp(b.path))
    }

    v.sort_by(cmp_by_timestamp_then_name);

    ...
} */

fn serve_forever(socket: ServerSocket, handler: ServerHandler) -> ! {
    socket.listen();
    loop {
        let s = socket.accept();
        handler.handle(s);
    }
}

fn main() {
    println!("Hello, world!");
}
