//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package tutorial_2;



network Network_Description
{
    @display("bgb=654,498");
    types:
        simple My_Node
        {
            gates:
                input input_gate;
                output output_gate;
        }

    submodules:
        // Define 5 nodes (computers)
        computer1: My_Node {
            @display("p=94,176;i=device/pc");
        }
        computer2: My_Node {
            @display("p=176,397;i=device/pc");
        }
        computer3: My_Node {
            @display("p=421,415;i=device/pc");
        }
        computer4: My_Node {
            @display("p=486,202;i=device/pc");
        }
        computer5: My_Node {
            @display("p=333,73;i=device/pc");
        }


   connections:
       computer1.output_gate --> computer2.input_gate;
       computer2.output_gate --> computer3.input_gate;
       computer3.output_gate --> computer4.input_gate;
       computer4.output_gate --> computer5.input_gate;
       computer5.output_gate --> computer1.input_gate;
}
