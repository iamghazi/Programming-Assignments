'''

About
-----
This Program is solution to
Ex.6, Page 581
of "Starting Out With Python, 3rd edition"

..

Problem
-------
Joe’s Automotive performs the following routine maintenance services:

1) Oil change—$30.00
2) Lube job—$20.00
3) Radiator flush—$40.00
4) Transmission flush—$100.00
5) Inspection—$35.00
6) Muffler replacement—$200.00
7) Tire rotation—$20.00

Write a GUI program with check buttons that allow the user to select any or all of these
services. When the user clicks a button the total charges should be displayed.

'''

import tkinter as tk
from tkinter import messagebox, Canvas
from PIL import ImageTk, Image


class Application(tk.Frame):
    """
    A class to Represent Tkinter Application

    ...

    Attributes
    ----------
    master:object
        root window

    Methods
    -------
    main_window
        Create and Pack all the Widgets
        for the Tkinter GUI.

    get_total
        Calculate Sum of Services, chosen.
    """

    def __init__(self, master=None):
        """
        Constructor for the Application Class
        Constructs all the necessary attributes for Application object

        :param master: Root/main window to hold all widgets
        """

        # Use super() to inherit Frame method from superclass tk
        super().__init__(master)

        # master window's Title and Geometry defined
        # and window resize set to False
        # Pack master
        self.master = master
        self.master.title("Joe's Automotive")
        self.master.geometry("560x600")
        self.master.resizable(False, False)
        self.pack()

        # Call for the main_window method
        self.main_window()

    def main_window(self):
        """
        Create and Pack all the Widgets for the Tkinter GUI.

        :return: None
        """

        # Create Top, Middle and Bottom frame for heading
        self.top_frame = tk.Frame(self.master)
        self.mid_frame = tk.Frame(self.master)
        self.bottom_frame = tk.Frame(self.master)

        # Create a Label for heading,
        # Services heading and Charges heading
        self.head = tk.Label(
            self.top_frame,
            text="\nWELCOME TO JOE'S AUTOMATIVE\n",
            font=("Arial Bold", 15),
        )

        self.service_head = tk.Label(
            self.top_frame, text="SERVICES" + "\t" * 3, font=("Times", 11)
        )

        self.charge_head = tk.Label(
            self.top_frame, text="CHARGES", font=("Times", 11)
        )

        # Create seven IntVar Object to use with
        # the Checkboxes for services
        self.check_1 = tk.IntVar()
        self.check_2 = tk.IntVar()
        self.check_3 = tk.IntVar()
        self.check_4 = tk.IntVar()
        self.check_5 = tk.IntVar()
        self.check_6 = tk.IntVar()
        self.check_7 = tk.IntVar()

        # Set the IntVar object to 0
        self.check_1.set(0)
        self.check_2.set(0)
        self.check_3.set(0)
        self.check_4.set(0)
        self.check_5.set(0)
        self.check_6.set(0)
        self.check_7.set(0)

        # Create the Checkboxes widget in mid-frame
        self.chckbox_1 = tk.Checkbutton(
            self.mid_frame,
            text="\nOil Change" + "\t" * 3 + "$ 30.00\n",
            variable=self.check_1,
        )

        self.chckbox_2 = tk.Checkbutton(
            self.mid_frame,
            text="\nLube Job" + "\t" * 4 + "$ 20.00\n",
            variable=self.check_2,
        )

        self.chckbox_3 = tk.Checkbutton(
            self.mid_frame,
            text="\nRadiator Flush" + "\t" * 3 + "$ 40.00\n",
            variable=self.check_3,
        )

        self.chckbox_4 = tk.Checkbutton(
            self.mid_frame,
            text="\nTransmission Flush" + "\t" * 3 + "$ 100.00\n",
            variable=self.check_4,
        )

        self.chckbox_5 = tk.Checkbutton(
            self.mid_frame,
            text="\nInspection" + "\t" * 3 + "$ 35.00\n",
            variable=self.check_5,
        )

        self.chckbox_6 = tk.Checkbutton(
            self.mid_frame,
            text="\nMuffler Replacement" + "\t" * 2 + "$ 200.00\n",
            variable=self.check_6,
        )

        self.chckbox_7 = tk.Checkbutton(
            self.mid_frame,
            text="\nTire Rotation" + "\t" * 3 + "$ 20.00\n",
            variable=self.check_7,
        )

        self.calc_btn = tk.Button(
            self.bottom_frame, text="TOTAL CHARGE", command=self.get_total
        )

        # Label to describe Total Charge
        self.total_desc = tk.Label(self.bottom_frame, text="\nTotal Charge ")

        # StringVar object will store the
        # value passed to it using set method
        # and will update the value wherever specified
        self.sum_str = tk.StringVar()

        # Label to show the Total Charge
        self.total_val = tk.Label(self.bottom_frame, textvariable=self.sum_str)
        # Pack TOTAL CHARGE Button
        self.calc_btn.pack()

        # Pack Labels
        self.head.pack(anchor="c")
        self.service_head.pack(side="left", anchor="w")
        self.charge_head.pack(anchor="e")

        # Pack Checkboxes
        self.chckbox_1.pack(anchor="w")
        self.chckbox_2.pack(anchor="w")
        self.chckbox_3.pack(anchor="w")
        self.chckbox_4.pack(anchor="w")
        self.chckbox_5.pack(anchor="w")
        self.chckbox_6.pack(anchor="w")
        self.chckbox_7.pack(anchor="w")

        # Pack TOTAL CHARGE Button
        self.calc_btn.pack()

        # Pack Total Labels
        self.total_desc.pack()
        self.total_val.pack()

        # Pack Top Frame
        self.top_frame.pack()
        self.mid_frame.pack()
        self.bottom_frame.pack()

    def get_total(self):
        """
        Calculate Sum of Services,
        chosen by User

        :return: None
        """

        # Total sum
        self.sum = 0.00

        # Determine which Check buttons are selected
        # and add the charges to find the total
        if self.check_1.get() == 1:
            self.sum += 30.00
        if self.check_2.get() == 1:
            self.sum += 20.00
        if self.check_3.get() == 1:
            self.sum += 40.00
        if self.check_4.get() == 1:
            self.sum += 100.00
        if self.check_5.get() == 1:
            self.sum += 35.00
        if self.check_6.get() == 1:
            self.sum += 200.00
        if self.check_7.get() == 1:
            self.sum += 20.00

        # Convert the sum to string
        # and store in StringVar object
        # to automatically update the total_val label
        self.sum_str.set(self.sum)


# Create our main window
root = tk.Tk()

# Create an instance of Application Class
app = Application(master=root)

# Enter the loop to keep the window running
app.mainloop()
