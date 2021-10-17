fn main() {
  let mut line = String::new();
  std::io::stdin().read_line(&mut line).unwrap();
  line = line.trim().to_string();
  let data = line.split(' ').map(|s| s.parse::<i64>().unwrap()).collect::<Vec<i64>>();
  println!("{}", data.get(0).unwrap() + data.get(1).unwrap());
}
