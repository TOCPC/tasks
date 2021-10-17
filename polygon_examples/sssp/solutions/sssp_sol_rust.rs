use std::collections::BinaryHeap;

fn main() {
  let mut nm = String::new();
  std::io::stdin().read_line(&mut nm).unwrap();
  nm = nm.trim().to_string();
  let mut vec: Vec<i64> = nm.split(' ').map(|s| s.parse::<i64>().unwrap()).collect(); 
  let n = *vec.get(0).unwrap() as usize;
  let m = *vec.get(1).unwrap() as u32;
  let mut g: Vec<Vec<(usize, i64)>> = vec![Vec::new(); n];
  for _ in 0..m {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    buf = buf.trim().to_string();
    vec = buf.split(' ').map(|s| s.parse::<i64>().unwrap()).collect();
    let u = (*vec.get(0).unwrap() - 1) as usize;
    let v = (*vec.get(1).unwrap() - 1) as usize;
    let w = *vec.get(2).unwrap();
    g[u].push((v, w));
    g[v].push((u, w));
  }
  let mut d: Vec<i64> = vec![1e18 as i64; n];
  let mut visit = vec![false; n];
  d[0] = 0;
  let mut heap = BinaryHeap::new();
  heap.push((0, 0));
  for _ in 0..n {
    let u = {
      while visit[heap.peek().unwrap().1] == true {
        heap.pop();
      }
      heap.pop().unwrap().1
    };
    visit[u] = true;
    for v in g[u].iter() {
      if d[v.0] > d[u] + v.1 {
        d[v.0] = d[u] + v.1;
        heap.push((-d[v.0], v.0));
      }
    }
  }
  let ans: String = d.iter().map(|s| s.to_string()).collect::<Vec<String>>().join(" ");
  println!("{}", ans);
}
