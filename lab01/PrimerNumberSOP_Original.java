/**
 * @author Mordecai
 * @version 1.0.0
 * @create 2020/2/25 16:26
 * @blog
 */
package chp01;

public class PrimerNumberSOP_Original {
    public static void main(String args[]) {
        int n = 50, global_cnt = 0;
        int sieve[] = new int[n - 1];
        int iCounter = 2, iMax, i;
        for (i = 0; i < n - 1; i++) {
            sieve[i] = i + 2;
        }

        iMax = (int) Math.sqrt(n);
        while (iCounter <= iMax) {
            for (i = 2 * iCounter - 2; i < n - 1; i += iCounter) {
                global_cnt++;
                sieve[i] = 0;
            }
            iCounter++;
        }

        for (i = 0; i < n - 1; i++)
            if (sieve[i] != 0) System.out.print(sieve[i] + " ");

        System.out.println("\n共迭代了：" + global_cnt + "次");
    }
}

