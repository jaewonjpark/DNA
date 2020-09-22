#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int pairs = 0;
int total = 0;
double mean = 0, variance = 0, standard_dev = 0, variance_sum = 0;
int lineNum = 0;

// single nucleotides
	int a = 0, c = 0,
  g = 0, t = 0;

// % nucleotides
  double a_percentage = 0, c_percentage = 0,
  g_percentage = 0, t_percentage = 0;


// bi Nucleotide
	int aa = 0, ac = 0, ag = 0, at = 0, ca = 0, cc = 0, cg = 0, ct = 0, ta = 0,
  tc = 0, tg = 0, tt = 0, ga = 0, gc = 0, gg = 0, gt = 0;


// % bi
	double aa_percent = 0, ac_percent = 0, ag_percent = 0, at_percent = 0, ca_percent = 0,
  cc_percent = 0, cg_percent = 0, ct_percent = 0, ta_percent = 0,
 tc_percent = 0, tg_percent = 0, tt_percent = 0, ga_percent = 0,
  gc_percent = 0, gg_percent = 0, gt_percent = 0;


int main(int argc, char** argv) //integer parameter
{
  string file;
  cout << "Enter DNA File" << endl;
	cin >> file;  //how to character input


  // Searched from Google
  // How to open the file using ifstream
	ifstream tst;
	tst.open(file);


	if (tst.is_open())
	{
		cout << " " << endl;
		string line = "";

		while (getline(tst, line))
		{
			cout << line << endl;
			total = total + line.size();
			lineNum++;
		}

    cout << " " << endl;

    // Getting total lines
		cout << "Total characters: " << total << endl;
    // Getting the mean value
		mean = total / lineNum;
		cout << "Mean values: " << mean << endl;


    // Getting the variance value
		while (getline(tst, line))
		{
			variance_sum += ((line.size() - mean) * (line.size() - mean));
    }

		variance = (variance_sum / (lineNum - 1));
		standard_dev = sqrt(variance);
		cout << "Variance is: " << variance << endl;
		cout << "Standard Deviation is: " << standard_dev << endl;


    // Allows you to seek to an arbitrary position in a file
		tst.clear();
		tst.seekg(0, ios::beg);


		while (getline(tst, line))
		{
      //Turn to Lowercase
			for (int i = 0; i < line.length(); ++i)
			{
				line[i] = tolower(line[i]);
			}

			for (int j = 0; j < line.length(); ++j)
			{
        //Increment of DNA pairs
				string pairedDNA = "";
				pairedDNA = line[j];
				pairedDNA += line[j + 1];

        // Increasing when both single and bi
				if (pairedDNA == "aa")
				{
					a++;
					a++;
					aa++;
				}
				else if (pairedDNA == "ac")
				{
					a++;
					c++;
					ac++;
				}
        else if (pairedDNA == "ag")
				{
					a++;
					g++;
					ag++;
				}
				else if (pairedDNA == "at")
				{
					a++;
					t++;
					at++;
				}
				else if (pairedDNA == "ca")
				{
					c++;
					a++;
					ca++;
				}
				else if (pairedDNA == "cc")
				{
					c++;
					c++;
					cc++;
				}
        else if (pairedDNA == "cg")
				{
					c++;
					g++;
					cg++;
				}
				else if (pairedDNA == "ct")
				{
					c++;
					t++;
					ct++;
				}
				else if (pairedDNA == "ta")
				{
					t++;
					a++;
					ta++;
				}
				else if (pairedDNA == "tc")
				{
					t++;
					c++;
					tc++;
				}
        else if (pairedDNA == "tg")
				{
					t++;
					g++;
					tg++;
				}
				else if (pairedDNA == "tt")
				{
					t++;
					t++;
					tt++;
				}
				else if (pairedDNA == "ga")
				{
					g++;
					a++;
					ga++;
				}
				else if (pairedDNA == "gc")
				{
					g++;
					c++;
					gc++;
				}
        else if (pairedDNA == "gg")
				{
					g++;
					g++;
					gg++;
				}
				else if (pairedDNA == "gt")
				{
					g++;
					t++;
					gt++;
				}
			}
		}
	}

  cout << " "<< endl;

	cout << "Amount of a: " << a << endl;
	cout << "Amount of c: " << c << endl;
	cout << "Amount of g: " << g << endl;
	cout << "Amount of t: " << t << endl;
	cout << "Amount of aa: " << aa << endl;
	cout << "Amount of ac: " << ac << endl;
	cout << "Amount of ag: " << ag << endl;
	cout << "Amount of at: " << at << endl;
	cout << "Amount of ca: " << ca << endl;
	cout << "Amount of cc: " << cc << endl;
	cout << "Amount of cg: " << cg << endl;
	cout << "Amount of ct: " << ct << endl;
	cout << "Amount of ta: " << ta << endl;
	cout << "Amount of tc: " << tc << endl;
	cout << "Amount of tg: " << tg << endl;
	cout << "Amount of tt: " << tt << endl;
	cout << "Amount of ga: " << ga << endl;
	cout << "Amount of gc: " << gc << endl;
	cout << "Amount of gg: " << gg << endl;
	cout << "Amount of gt: " << gt << endl;

  cout << " "<< endl;

  pairs = (total / 2);
	a_percentage = ((double)a / total);
	c_percentage = ((double)c / total);
	g_percentage = ((double)g / total);
	t_percentage = ((double)t / total);
  aa_percent = ((double)aa / pairs);
	ac_percent = ((double)ac / pairs);
	ag_percent = ((double)ag / pairs);
	at_percent = ((double)at / pairs);
	ca_percent = ((double)ca / pairs);
	cc_percent = ((double)cc / pairs);
	cg_percent = ((double)cg / pairs);
	ct_percent = ((double)ct / pairs);
	ta_percent = ((double)ta / pairs);
	tc_percent = ((double)tc / pairs);
	tg_percent = ((double)tg / pairs);
	tt_percent = ((double)tt / pairs);
	ga_percent = ((double)ga / pairs);
	gc_percent = ((double)gc / pairs);
	gg_percent = ((double)gg / pairs);
	gt_percent = ((double)gt / pairs);


	cout << "Percent of a: " << a_percentage << endl;
	cout << "Percent of c: " << c_percentage << endl;
	cout << "Percent of g: " << g_percentage << endl;
	cout << "Percent of t: " << t_percentage << endl;
	cout << "Percent of aa: " << aa_percent << endl;
	cout << "Percent of ac: " << ac_percent << endl;
	cout << "Percent of ag: " << ag_percent << endl;
	cout << "Percent of at: " << at_percent << endl;
	cout << "Percent of ca: " << ca_percent << endl;
	cout << "Percent of cc: " << cc_percent << endl;
	cout << "Percent of cg: " << cg_percent << endl;
	cout << "Percent of ct: " << ct_percent << endl;
	cout << "Percent of ta: " << ta_percent << endl;
	cout << "Percent of tc: " << tc_percent << endl;
	cout << "Percent of tg: " << tg_percent << endl;
	cout << "Percent of tt: " << tt_percent << endl;
	cout << "Percent of ga: " << ga_percent << endl;
	cout << "Percent of gc: " << gc_percent << endl;
	cout << "Percent of gg: " << gg_percent << endl;
	cout << "Percent of gt: " << gt_percent << endl;


  //output is different from cout
  //output prints in jaewonpark.out
  //and cout prints in the terminal
	ofstream output("jaewonpark.out");
	output << "Jaewon Park" << endl;
	output << "Chapman ID: 2328614" << endl;
	output << "1000 DNA listed: " << endl;
  output << " " << endl;
  output << "Percent of a: " << a_percentage << endl;
	output << "Percent of c: " << c_percentage << endl;
	output << "Percent of g: " << g_percentage << endl;
	output << "Percent of t: " << t_percentage << endl;
	output << "Percent of aa: " << aa_percent << endl;
	output << "Percent of ac: " << ac_percent << endl;
	output << "Percent of ag: " << ag_percent << endl;
	output << "Percent of at: " << at_percent << endl;
	output << "Percent of ca: " << ca_percent << endl;
	output << "Percent of cc: " << cc_percent << endl;
	output << "Percent of cg: " << cg_percent << endl;
	output << "Percent of ct: " << ct_percent << endl;
	output << "Percent of ta: " << ta_percent << endl;
	output << "Percent of tc: " << tc_percent << endl;
	output << "Percent of tg: " << tg_percent << endl;
	output << "Percent of tt: " << tt_percent << endl;
	output << "Percent of ga: " << ga_percent << endl;
	output << "Percent of gc: " << gc_percent << endl;
	output << "Percent of gg: " << gg_percent << endl;
	output << "Percent of gt: " << gt_percent << endl;

  output << " " << endl;

  // To generate the length of a string from a Gaussian distribution
	double gaussian_A = 0, gaussian_B = 0, gaussian_C = 0;
	int gaussian_D = 0;
	double percent_pair = 0;


	for(int i = 0; i < 1000; i++)
	{
    output << " "<< endl; // To make it look neater
		gaussian_A = ((double) rand() / (RAND_MAX));
		gaussian_B = ((double) rand() / (RAND_MAX));

    // Formula from "Hint"
		gaussian_C = (sqrt(-2 * log(gaussian_A)) * (cos(2 * M_PI * gaussian_B)));
		gaussian_D = ((standard_dev * gaussian_C) + mean);


		for (int j=0; i < (gaussian_D/2); ++j)
		{
			percent_pair = ((double) rand() / (RAND_MAX));

			if (percent_pair <= aa_percent)
			{
				output << "aa";
			}
			else if (percent_pair <= (aa_percent + ac_percent))
			{
				output << "ac";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent))
			{
				output << "ag";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent))
			{
				output << "at";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent))
			{
				output << "ca";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent))
			{
				output << "cc";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent))
			{
				output << "cg";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent))
			{
				output << "ct";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent))
			{
				output << "ta";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent))
			{
				output << "tc";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent + tg_percent))
			{
				output << "tg";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent + tg_percent + tt_percent))
			{
				output << "tt";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent + tg_percent + tt_percent + ga_percent))
			{
				output << "ga";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent + tg_percent + tt_percent + ga_percent + gc_percent))
			{
				output << "gc";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent + tg_percent + tt_percent + ga_percent + gc_percent + gg_percent))
			{
				output << "gg";
			}
			else if (percent_pair <= (aa_percent + ac_percent + ag_percent + at_percent + ca_percent + cc_percent + cg_percent + ct_percent + ta_percent + tc_percent + tg_percent + tt_percent + ga_percent + gc_percent + gg_percent + gt_percent))
			{
				output << "gt";
			}
		}
}
  return 0;
}
