using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kyanite.Sentinel
{
	internal interface ICommand
	{
		Task Execute(string[] args, CommandDispatcher dispatch);
		public string Command { get; set; }
	}
}
