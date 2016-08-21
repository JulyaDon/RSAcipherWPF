using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;

namespace RSAcipherWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("RSAcipherDLL.dll", EntryPoint = "mainRSA", CallingConvention = CallingConvention.Cdecl, ExactSpelling = false, CharSet = CharSet.Ansi)]
        public static extern IntPtr mainRSA([MarshalAs(UnmanagedType.LPStr)]string sentence, int p, int q);
        public MainWindow()
        {
            InitializeComponent();
        }
        private void GreetMeButton_Click(object sender, RoutedEventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(FirstName.Text))
            {
                IntPtr resultPtr = mainRSA(FirstName.Text, Convert.ToInt32(simpleP.Text), Convert.ToInt32(simpleQ.Text));

                string resultString = Marshal.PtrToStringAnsi(resultPtr);
                CipheredText.Text = resultString;
            }
        }
    }
}
