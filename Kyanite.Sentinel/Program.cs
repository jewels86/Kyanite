using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Kyanite.Sentinel;

public static class Program
{
	public static async Task Main(string[] args)
	{
		await SentinelCLI.Run();
	}
}