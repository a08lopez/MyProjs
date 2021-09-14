using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;
using System.Windows;

/* This program will create a calculator that will convert
 * Illuminate scores to Edgenuity scores. Note Edgenuity scores
 * are simply scores that follow the standard grade scale (i.e. 70-79 a C,
 * 80-89 a B, 90-100 an A). This program uses if statements 
 * in order to correctly choose the score in order to help it
 * convert the score. And uses a mathemtical formula to acomplish the task.
 * Furthermore the xaml page is utilized in order add GUI functionalities.
 */
namespace IlluminatetoEdgenuity
{
    public partial class MainPage : ContentPage
    {
        
        public MainPage()
        {
            InitializeComponent();

        }
		/* Name: Clear_Clicked 
		 * Param: sender object, Event handler e 
		 * returns: nothing
		 */
		 /* Clear_Clicked clears the text boxes in the
		  * app in order for user to insert new score values
		  * to calculate
		  */
        private void Clear_Clicked(object sender, EventArgs e)
        {
            illum.Text = "  ";
            edge.Text = "  ";
            success.Text = "  ";
        }
		/* Name: Convert_Clicked 
		 * Param: sender object, Event handler e 
		 * returns: nothing
		 */
		 /* Convert_Clicked allows user to convert Illuminate scores
		  * into Edgenuity scores by providing user input and returning
		  * to a textbox if Converted Successfully.
		  */
        private void Convert_Clicked(object sender, EventArgs e)
        {
            double illumScore = 0.0;

            string val = illum.Text;
            double edgeScore = 0.0;

            if (Double.TryParse(val, out illumScore))
            {
                if (illumScore >= 0)
                {
                    if (illumScore >= 81.0 && illumScore <= 100.0)
                    {
                        edgeScore = (illumScore - 81.0) / (100.0 - 81.0) * (100.0 - 90.0) + 90.0;
                    }
                    else if (illumScore >= 71.0 && illumScore <= 80.99)
                    {
                        edgeScore = (illumScore - 71.0) / (80.99 - 71.0) * (89.99 - 80.0) + 80.0;
                    }
                    else if (illumScore >= 62.0 && illumScore <= 70.0)
                    {
                        edgeScore = (illumScore - 62.0) / (70.0 - 62.0) * (79.99 - 70.0) + 70.0;
                    }
                    else
                    {
                        edgeScore = illumScore;
                    }
                    edgeScore = Math.Round(edgeScore, 2);
                    edge.Text = edgeScore.ToString();

                    success.Text = "Converted Succesfully!";
                }
                else
                {
                    success.Text = "Illuminate score cannot be negative!";
                }
            }
            else
            {
                success.Text = "Illuminate score needs to be an integer or decimal!";
            }


        }

    }
}
