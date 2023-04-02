use trait_objects::{Screen, SelectBox, Button};

fn main() {
    let screen = Screen {
        components: vec![
            Box::new(SelectBox {
                width: 75,
                height: 10,
                options: vec![
                    String::from("Yes"),
                    String::from("Maybe"),
                    String::from("No"),
                ],
            }),
            Box::new(Button {
                width: 75,
                height: 10,
                label: "Ok".to_string(),
            })
        ],
    };

    screen.run();
}
