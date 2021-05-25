**
 * @author : Qin Zhenghan
 * @date : Created in 2021/3/14
 * @description: 约瑟夫环结构化实现
 */
public class JosephRing {
    public void joseph(int n, int m){
        //n为总人数，m为报数
        int[] arr = new int[n+1];  //数组
        int num = 0;  //报数器
        int count = 0;  //报数计数器，数到m清零
        int fall = 0;  //淘汰人数
        //数组初始化，1为未被淘汰,0为被淘汰
        for(int i = 1; i < n+1; i++){
            arr[i] = 1;
        }
        while(fall != n){
            num++;
            //循环数组
            if(num > n){
                num = 0;
            }
            if(arr[num] == 1){
                count++;
                if(count == m){
                    arr[num] = 0;
                    fall++;
                    count = 0;
                }
            }
        }
        //输出最后留下的序号
        System.out.println(num);
    }

    public static void main(String[] args){
        JosephRing jr = new JosephRing();
        jr.joseph(10, 3);
    }
}