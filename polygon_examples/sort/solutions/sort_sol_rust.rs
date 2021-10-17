fn main() {
  let mut line = String::new();
  std::io::stdin().read_line(&mut line).unwrap();
  line = String::new();
  std::io::stdin().read_line(&mut line).unwrap();
  line = line.trim().to_string();
  let mut vec: Vec<i64> = line.split(' ').map(|s| s.parse::<i64>().unwrap()).collect();
  vec.sort_by(|a, b| a.partial_cmp(b).unwrap());
  let ans: String = vec.iter().map(|s| s.to_string()).collect::<Vec<String>>().join(" ");
  println!("{}", ans);
}
