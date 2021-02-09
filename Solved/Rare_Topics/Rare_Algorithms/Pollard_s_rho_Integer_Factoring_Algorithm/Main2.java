import java.math.*;
import java.security.SecureRandom;
import java.util.*;
import java.io.*;



class Main2 {
  public static TreeMap<BigInteger, Integer> mapper = new TreeMap<>();
  private static BigInteger TWO = BigInteger.valueOf(2);
  private final static SecureRandom random = new SecureRandom();

  private static BigInteger f(BigInteger x, BigInteger b, BigInteger n) {
    return x.multiply(x).mod(n).add(b).mod(n);     // x = (x^2 % n + b) % n
  }

  private static BigInteger rho(BigInteger n) {
    if (n.mod(TWO).compareTo(BigInteger.ZERO) == 0) return TWO;  // special
    BigInteger b = new BigInteger(n.bitLength(), random);  // rand for luck
    BigInteger x = new BigInteger(n.bitLength(), random);
    BigInteger y = x;                                    // initially y = x
    while (true) {
      x = f(x, b, n);                                           // x = f(x)
      y = f(f(y, b, n), b, n);                               // y = f(f(y))
      BigInteger d = x.subtract(y).gcd(n);                 // d = (x-y) % n
      if (d.compareTo(BigInteger.ONE) != 0)                    // if d != 1
        return d;          // d is one of the divisor of composite number n
  } }

  public static void pollard_rho(BigInteger n) {
    if (n.compareTo(BigInteger.ONE) == 0) return;    // special case, n = 1
    if (n.isProbablePrime(10)) {
      //System.out.println(n); 
      mapper.merge(n, 1, Integer::sum);
      return;  // n is a prime, the only factor is n
    }
    BigInteger divisor = rho(n);   // n is a composite number, can be split
    pollard_rho(divisor);                     // recursive check to divisor
    pollard_rho(n.divide(divisor));                        // and n/divisor
  }

  public static void main(String[] args) throws Exception{
     BufferedReader br = new BufferedReader(      // use BufferedReader
      new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(            // and PrintWriter
      new BufferedWriter(new OutputStreamWriter(System.out))); // = fast IO
   String st;
   while((st = br.readLine()) != null){
     if(st.compareTo("0") == 0) break;
     BigInteger n = new BigInteger(st);
     pollard_rho(n);       // factorize n to 7 x 124418296927 x 143054969437
    if(mapper.size()  == 1) {
         Map.Entry<BigInteger,Integer> f = mapper.firstEntry();
         pw.printf(f.getKey().toString());
         pw.printf("^%d", f.getValue());
        pw.printf("\n");
    }else{
        Map.Entry<BigInteger,Integer> f = mapper.firstEntry();
        pw.printf(f.getKey().toString());
         pw.printf("^%d", f.getValue());
        int c = 0;
        for(Map.Entry<BigInteger,Integer> m : mapper.entrySet()) {
          if(c == 0){
            ++c;
            continue;
          }
          pw.printf(" ");
          pw.printf(m.getKey().toString());
            pw.printf("^%d", m.getValue());
        }
        pw.printf("\n");
    }
     mapper.clear();
   }
   pw.close();
  }
}